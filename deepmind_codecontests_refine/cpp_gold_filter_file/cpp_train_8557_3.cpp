#include <bits/stdc++.h>
using namespace std;
long long calc(long long x, long long n) {
  long long ans = 0, dig = 0;
  while (x <= n) {
    ans += min(n - x + 1, 1ll << dig);
    x <<= 1;
    dig++;
  }
  return ans;
}
signed main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  long long l = 0, r = n / 2 + 1;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (calc(mid * 2 + 1, n) >= k)
      l = mid;
    else
      r = mid;
  }
  long long ans = l * 2 + 1;
  l = 0, r = n / 2 + 1;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (calc(mid * 2, n) + calc(mid * 2 + 1, n) >= k)
      l = mid;
    else
      r = mid;
  }
  ans = max(ans, l * 2);
  printf("%lld", ans);
  return 0;
}
