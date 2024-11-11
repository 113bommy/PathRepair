#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 10;
int nums[Maxn] = {0};
long long points[Maxn] = {0};
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];
  sort(nums, nums + n);
  points[0] = 0;
  points[1] = nums[0];
  for (int i = 1; i < n; i++) {
    if (nums[i] > nums[i - 1] + 1) {
      points[i + 1] = points[i] + nums[i];
    } else if (nums[i] == nums[i - 1]) {
      long long first, second;
      int low = lower_bound(nums, nums + n, nums[i]) - nums;
      int lowm = lower_bound(nums, nums + n, nums[i] - 1) - nums;
      first = nums[i] * (i - low + 1) + points[lowm];
      second = points[low];
      points[i + 1] = max(first, second);
    } else {
      long long first = points[i];
      long long second = nums[i];
      int low = lower_bound(nums, nums + n, nums[i - 1]) - nums;
      second += points[low];
      points[i + 1] = max(first, second);
    }
  }
  cout << points[n] << endl;
  return 0;
}
