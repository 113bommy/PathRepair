#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, q;
long long fa[500010], pre[500010], sum[500010], tot[500010], ans[500010],
    power[500010], haha[500010], a[500010];
struct arr {
  long long l, r, n;
} ask[500010];
long long cmp(arr x, arr y) { return x.r < y.r; }
void merge(long long x, long long y) {
  fa[x] = y;
  pre[y] = pre[x];
  long long len = x - pre[x];
  if ((len >= 30 && sum[y] > 0) || sum[x] + (sum[y] << len) >= mod)
    sum[y] = mod;
  else
    sum[y] = sum[x] + (sum[y] << len);
}
long long find(long long u) {
  if (fa[u] == u) return u;
  fa[u] = find(fa[u]);
  return fa[u];
}
long long calc(long long x, long long y) {
  return ((haha[x] - haha[y + 1] * power[y - x + 1] % mod) + mod) % mod;
}
signed main() {
  scanf("%lld%lld", &n, &q);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long i = 1; i <= q; i++) {
    scanf("%lld%lld", &ask[i].l, &ask[i].r);
    ask[i].n = i;
  }
  sort(ask + 1, ask + 1 + q, cmp);
  power[0] = 1;
  for (long long i = 1; i <= n; i++) power[i] = power[i - 1] * 2 % mod;
  haha[n] = a[n];
  for (long long i = n - 1; i >= 1; i--)
    haha[i] = ((haha[i + 1] * 2 % mod + a[i]) % mod + mod) % mod;
  for (long long i = 1; i <= n; i++) pre[i] = i - 1, fa[i] = i, sum[i] = a[i];
  long long j = 1;
  for (long long i = 1; i <= n; i++) {
    while (pre[i] && sum[i] >= 0) merge(pre[i], i);
    tot[i] =
        ((tot[pre[i]] + (calc(pre[i] + 1, i) << 1) % mod) % mod + mod) % mod;
    while (j <= q && ask[j].r == i) {
      long long num = find(ask[j].l);
      ans[ask[j].n] =
          ((((tot[i] - tot[num]) % mod + mod) % mod + calc(ask[j].l, num)) %
               mod +
           mod) %
          mod;
      j++;
    }
  }
  for (long long i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}
