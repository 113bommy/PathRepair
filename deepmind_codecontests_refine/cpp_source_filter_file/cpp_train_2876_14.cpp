#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, fa[500100], pre[500100], p2[500100], a[500100], sur[500100],
    val[500100], d[500100], ans[500100];
vector<pair<long long, long long> > v[500100];
inline long long sf(long long x) { return fa[x] == x ? x : fa[x] = sf(fa[x]); }
inline long long q(long long x, long long y) {
  return (sur[x] - sur[y + 1] * p2[y - x + 1] % mod + mod) % mod;
}
inline void mer(long long x, long long y) {
  if ((x - pre[x] >= 30 && val[y] > 0) ||
      (val[x] + (val[y] << (x - pre[x]))) > mod)
    val[x] = mod;
  else
    val[y] = val[x] + (val[y] << (x - pre[x]));
  fa[x] = fa[y];
  pre[y] = pre[x];
  return;
}
signed main() {
  long long i, j, k;
  scanf("%lld%lld", &n, &m);
  for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (i = 1; i <= n; i++) pre[i] = i - 1, fa[i] = i;
  p2[0] = 1;
  for (i = 1; i <= n; i++) p2[i] = (p2[i - 1] << 1) % mod;
  for (i = n; i > 0; i--) sur[i] = ((sur[i + 1] << 1) % mod + a[i] + mod) % mod;
  for (i = 1; i <= m; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y), v[y].push_back(make_pair(x, i));
  }
  for (i = 1; i <= n; i++) {
    val[i] = a[i];
    while (pre[i] && val[i] >= 0) mer(pre[i], i);
    d[i] = (d[pre[i]] + (q(pre[i] + 1, i) << 1) % mod + mod) % mod;
    for (j = 0; j < v[i].size(); j++) {
      long long x = v[i][j].first, id = v[i][j].second, y = sf(x);
      ans[id] = (d[i] - d[y] + q(x, y) + mod) % mod;
    }
  }
  for (i = 1; i <= m; i++) printf("%lld\n", ans[i]);
  return 0;
}
