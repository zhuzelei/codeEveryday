#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define maxNumLen 500

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int oriSum = 0;
        int sonSum = 0;
        int posSum[maxNumLen] = {0};
        int posFlag = 0;
        for (auto i : nums) {
            oriSum += i;
            posSum[posFlag] = oriSum;
            posFlag++;
        }

        int left = 0;
        int numsSize = nums.size();
        int right = numsSize - 1;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            cout << "left" << left << " right" << right << " mid" << mid <<endl;

            cout << "a" << posSum[numsSize - 1] << " b" << posSum[mid] <<endl;
            if (posSum[numsSize - 1] - posSum[mid] <= posSum[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int resCnt = numsSize - mid;

        vector<int> result;
        for (int i = 0; i < resCnt; i++) {
            result.push_back(nums[numsSize - 1- i]);
        }

        return result;
    }
};


int main() {
    int arrayNum[] = {4, 4, 7, 6, 7};
    vector<int> nums(arrayNum, arrayNum + 5);

    Solution sol;
    vector<int> res = sol.minSubsequence(nums);

    for (auto i : res) {
        cout << i << " ";
    }
    return 0;
}
