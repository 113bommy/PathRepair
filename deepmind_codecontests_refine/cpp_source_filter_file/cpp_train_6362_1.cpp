#include <bits/stdc++.h>
using namespace std;
long long n, l, r, k, a;
signed main() {
  scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
  a = (r - l + n + 1) % n;
  long long ans = -1;
  for (long long i = 1, j; i <= k; i = j + 1) {
    long long cnt = k / i;
    j = k / cnt;
    long long lp = max(n, i);
    long long rp = min(2 * n, j);
    lp = max(lp, (k - 2 * a + cnt - 1) / cnt);
    rp = min(rp, min((2 * n + k - 2 * a + 1) / (cnt + 1), (k - a) / cnt));
    if (lp <= rp) ans = max(ans, rp - n);
  }
  if (k >= a && k >= a * 2) ans = max(ans, min(a, k - a + 1) + (n - a));
  if (!a && k == n) ans = max(ans, 1ll);
  printf("%lld\n", ans);
  return 0;
}
