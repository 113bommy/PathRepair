#include <bits/stdc++.h>
using namespace std;
long long n, nums[300003], ans;
int main() {
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &nums[i]);
  }
  sort(nums, nums + n);
  for (int i = 0; i < (n / 2); i++) {
    ans += (nums[i] + nums[n - 1 - i]) * (nums[i] + nums[n - 1 - i]);
  }
  printf("%lld\n", ans);
  return 0;
}
