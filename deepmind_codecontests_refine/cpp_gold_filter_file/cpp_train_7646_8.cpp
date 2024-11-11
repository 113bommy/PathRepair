#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 10, inf = 1e9;
long long sz[N], subT[N], cnt[N], par[N], mark[N], h[N], reach[N];
vector<long long> G[N], comp[N];
vector<pair<long long, long long> > g[N];
bitset<N> dp;
void init(long long n) {
  for (long long i = 1; i <= n; i++) par[i] = i;
}
long long getpar(long long u) {
  return (par[u] == u ? u : par[u] = getpar(par[u]));
}
void Union(long long u, long long v) {
  u = getpar(u);
  v = getpar(v);
  par[u] = v;
}
long long dfs(long long v, long long height = 0, long long id = 0,
              long long par = 0) {
  mark[v] = 1, h[v] = height;
  long long top = inf;
  for (auto p : g[v]) {
    long long u = p.first, e = p.second;
    if (!mark[u]) top = min(top, dfs(u, height + 1, e, v));
    if (mark[u] == 1 && e != id) top = min(top, h[u]);
  }
  if (top < height) Union(par, v);
  mark[v] = 2;
  return top;
}
void DFS(long long v, long long par = 0) {
  for (auto u : G[v])
    if (u != par) {
      DFS(u, v);
      subT[v] += subT[u];
      reach[v] += reach[u] + sz[v] * subT[u];
    }
  subT[v] += sz[v];
  return;
}
long long Main(long long n, long long SZ) {
  long long c = 1, par = 0;
  DFS(c);
  bool val = 0;
  while (!val) {
    val = 1;
    for (auto u : G[c])
      if (u != par) {
        if (subT[u] * 2 > SZ) {
          par = c, c = u, val = 0;
          break;
        }
      }
  }
  memset(subT, 0, sizeof subT);
  DFS(c);
  dp[0] = 1;
  for (auto u : G[c]) cnt[subT[u]]++;
  for (long long i = 1; i < SZ; i++) {
    if (cnt[i] > 2) {
      if (cnt[i] % 2 == 0) {
        cnt[i * 2] += cnt[i] / 2 - 1;
        cnt[i] = 2;
      } else {
        cnt[i * 2] += cnt[i] / 2;
        cnt[i] = 1;
      }
    }
    for (long long j = 0; j < cnt[i]; j++) dp |= dp << i;
  }
  long long ans = 0;
  for (long long i = 0; i < SZ; i++)
    if (dp[i]) ans = max(ans, (SZ - i - sz[c]) * i);
  for (long long i = 1; i <= n; i++) ans += subT[i] * sz[i];
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, m;
  cin >> n >> m;
  init(n);
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  dfs(1);
  long long C = 1;
  for (long long i = 1; i <= n; i++) comp[getpar(i)].push_back(i);
  for (long long i = 1; i <= n; i++)
    if (comp[i].size() > 0) {
      for (long long v : comp[i]) par[v] = C;
      sz[C++] = (long long)comp[i].size();
    }
  for (long long v = 1; v <= n; v++)
    for (auto u : g[v])
      if (par[v] != par[u.first]) G[par[v]].push_back(par[u.first]);
  long long ans = Main(C - 1, n);
  cout << ans << "\n";
}
