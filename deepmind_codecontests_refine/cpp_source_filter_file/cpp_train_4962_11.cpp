#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, t;
  cin >> n >> a >> b >> c >> t;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) cin >> nums[i];
  sort(nums.begin(), nums.end());
  long long ans = 0;
  for (auto x : nums) {
    ans += t;
    if (c > b) {
      ans += (c - b) * (t - x);
    };
  };
  printf("%lld\n", ans);
};
