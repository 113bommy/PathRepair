#include <bits/stdc++.h>
const long long N = 200005;
long long n, c, a[N << 1], st[N << 1], ans[N], T;
long long cal(long long x) { return ans[x] - a[2 * x]; }
signed main() {
  T = 1;
  while (T--) {
    scanf("%lld%lld", &n, &c);
    memset(ans, 0, sizeof(ans));
    for (long long i = 1; i < 2 * n; i++) scanf("%lld", &a[i]);
    for (long long i = 1; i < 2 * n; i++) a[i] += a[i - 1];
    long long p = 0, l = 0, r = 0;
    for (long long i = 1; i <= n; i++) {
      while (p <= n && a[2 * i - 1] - a[2 * p] >= c) p++;
      while (l <= r && a[2 * i - 1] - a[2 * st[l]] >= c) l++;
      if (p) ans[i] = ans[p - 1] + c;
      if (l <= r) ans[i] = std::max(ans[i], a[2 * i - 1] + cal(st[l]));
      while (l <= r && cal(i) >= cal(st[r])) r--;
      st[++r] = i;
    }
    printf("%lld\n", ans[n]);
  }
}
