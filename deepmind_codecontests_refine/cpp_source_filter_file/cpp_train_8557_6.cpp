#include <bits/stdc++.h>
using namespace std;
long long n, k, ans;
inline long long g(long long S) {
  long long res = 0, num = 1;
  while (S <= n) {
    res += min(num, n - S + 1);
    S <<= 1, num <<= 1;
  }
  return res;
}
signed main() {
  scanf("%lld%lld", &n, &k);
  long long l, r, mid, res;
  l = 1, r = n / 2, res = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (g(mid * 2) + g(mid * 2 + 1) >= k)
      res = mid * 2, l = mid + 1;
    else
      r = mid - 1;
  }
  ans = max(ans, res);
  l = 1, r = n / 2, res = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (g(mid * 2 - 1) >= k)
      res = mid * 2 - 1, l = mid + 1;
    else
      r = mid - 1;
  }
  ans = max(ans, res);
  printf("%lld", ans);
  return 0;
}
