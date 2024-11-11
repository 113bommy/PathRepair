#include <bits/stdc++.h>
inline long long sbt(long long x) { return __builtin_popcount(x); }
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
vector<pair<long long, long long> > adj[100013];
long long n, k;
long long pre[100013];
long long par[19][100013];
long long vis[100013], lev[100013], res[100013];
void dfs(long long node, long long p, long long edge, long long level) {
  vis[node] = edge;
  par[0][node] = p;
  lev[node] = level;
  for (auto nei : adj[node]) {
    if (nei.first != p) dfs(nei.first, node, nei.second, level + 1);
  }
}
long long lca(long long u, long long v) {
  if (lev[u] < lev[v]) {
    swap(u, v);
  }
  long long leveldiff = lev[u] - lev[v];
  for (long long i = 19 - 1; i >= 0; i--)
    if ((1 << i) & leveldiff) u = par[i][u];
  if (u == v) return u;
  for (long long i = 19 - 1; i >= 0; i--) {
    if (par[i][u] && par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][u];
}
long long dfs1(long long node, long long p) {
  long long sum = 0;
  for (auto nei : adj[node]) {
    if (nei.first != p) {
      sum += dfs1(nei.first, node);
    }
  }
  res[vis[node]] = (sum + pre[node]);
  return (sum + pre[node]);
}
int32_t main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin >> n;
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(make_pair(v, i));
    adj[v].push_back(make_pair(u, i));
  }
  dfs(1, 0, 0, 0);
  for (long long i = 1; i < 19; i++)
    for (long long j = 1; j <= n; j++)
      if (par[i - 1][j]) par[i][j] = par[i - 1][par[i - 1][j]];
  cin >> k;
  while (k--) {
    long long u, v;
    cin >> u >> v;
    pre[u]++;
    pre[v]++;
    pre[lca(u, v)] -= 2;
  }
  dfs1(1, 0);
  for (long long i = 1; i < n; i++) {
    cout << res[i] << ' ';
  }
  return 0;
}
