#include <vector>
using namespace std;

vector<int> subArraySum(vector<int>& arr, int target) {
    int n = arr.size();
    long long current_sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        current_sum += arr[right];

        while (current_sum > target && left <= right) {
            current_sum -= arr[left];
            left++;
        }

        if (current_sum == target) {
            return {left + 1, right + 1}; 
        }
    }

    return {-1};
}
