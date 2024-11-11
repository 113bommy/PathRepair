#include <bits/stdc++.h>
using namespace std;
long long n, m, k, a[600000], b[600000], f[600000], g[600000], pre[600000],
    p[600000];
bool cmp(long long x, long long y) { return f[x] < f[y]; }
void solve() {
  scanf("%lld%lld%lld", &m, &n, &k);
  for (long long i = 1; i <= n; ++i) scanf("%lld", a + i);
  k += n + 1;
  for (long long i = 1; i <= n; ++i) b[i] = a[i] - a[i - 1];
  b[n + 1] = m - a[n];
  ++n;
  long long l = 1, r = m, L, R;
  while (l <= r) {
    long long mid = (l + r) >> 1, sum = 0;
    for (long long i = 1; i <= n; ++i) sum += (b[i] + mid - 1) / mid;
    if (sum <= k) {
      R = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  l = 1, r = m;
  for (long long i = 1; i <= n; ++i) r = min(r, b[i]);
  while (l <= r) {
    long long mid = (l + r) >> 1, sum = 0;
    for (long long i = 1; i <= n; ++i) sum += b[i] / mid;
    if (sum >= k) {
      L = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  for (long long i = 1; i <= n; ++i) {
    long long t = b[i] / L;
    g[i] = max(R, (b[i] + t - 1) / t);
    t = (b[i] + R - 1) / R;
    f[i] = min(L, b[i] / t);
    p[i] = i;
  }
  sort(p + 1, p + n + 1, cmp);
  pre[0] = R;
  for (long long i = 1; i <= n; ++i) pre[i] = max(pre[i - 1], g[p[i]]);
  long long ans = pre[n] - L;
  for (long long i = n; i; --i) ans = min(ans, pre[i - 1] - f[p[i]]);
  printf("%lld\n", ans);
}
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) solve();
  return 0;
}
