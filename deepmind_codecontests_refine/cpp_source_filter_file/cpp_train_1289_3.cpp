#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5 * 1010;
const long long INF = 0x3f3f3f3f3f3f;
long long n, ans = INF, sz[MAXN], dist[MAXN];
vector<tuple<long long, long long, long long>> e;
vector<pair<long long, long long>> g[MAXN];
void szdfs(long long v, long long p) {
  sz[v] = 1, dist[v] = 0;
  for (const auto& [w, u] : g[v])
    if (u != p) szdfs(u, v), sz[v] += sz[u], dist[v] += dist[u] + w * sz[u];
}
long long f(long long v, long long p, long long rt = 0) {
  if (!rt) rt = v;
  long long ret = 0;
  for (const auto& [w, u] : g[v])
    if (u != p) ret += f(u, v, rt) + (sz[rt] - sz[u]) * sz[u] * w;
  return ret;
}
long long mindist(long long v, long long p, long long rt = 0, long long x = 0) {
  if (!rt) rt = v, x = dist[v];
  long long ret = x;
  for (const auto& [w, u] : g[v])
    if (u != p)
      ret = min(ret, mindist(u, v, rt, x - 2 * sz[u] * w + sz[rt] * w));
  return ret;
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1, u, v, w; i < n; ++i)
    scanf("%lld %lld %lld", &u, &v, &w), e.push_back(make_tuple(u, v, w)),
        g[u].push_back(make_pair(w, v)), g[v].push_back(make_pair(w, u));
  for (const auto& [u, v, w] : e) {
    szdfs(u, v), szdfs(v, u);
    long long x = f(u, v), y = f(v, u), k;
    k = x + y + sz[u] * mindist(v, u) + sz[v] * mindist(u, v) +
        sz[u] * sz[v] * w;
    ans = min(ans, k);
  }
  printf("%lld\n", ans);
}
