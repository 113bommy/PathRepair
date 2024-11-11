#include <bits/stdc++.h>
using namespace std;
const int MX = 3e3 + 5, MXX = 23;
const long long mod = 1e9 + 7, inf = 1e18 + 6;
vector<int> G[MX];
long long dp[MX][MX], sz[MX], par[MXX][MX], hig[MX], mxa, n;
void dfs(int u) {
  for (auto v : G[u])
    if (v != par[0][u]) {
      par[0][v] = u;
      hig[v] = hig[u] + 1;
      dfs(v);
      sz[u] += sz[v];
    }
}
int anc(int u, int dis) {
  for (int i = 0; i < MXX; ++i)
    if (dis & 1 << i) u = par[i][u];
  return u;
}
int dis(int u, int v) {
  int ans = 0;
  if (hig[v] < hig[u]) swap(u, v);
  ans += hig[v] - hig[u];
  v = anc(v, hig[v] - hig[u]);
  if (v == u) return ans;
  for (int i = MXX - 1; i >= 0; i--)
    if (par[i][u] != par[i][v])
      ans += (1 << i + 1), u = par[i][u], v = par[i][v];
  return ans + 2;
}
void lca(int u, int v) {
  if (hig[v] < hig[u]) swap(u, v);
  if (u == anc(v, hig[v] - hig[u])) {
    int x = par[0][v];
    int y = anc(v, hig[v] - hig[u] - 1);
    dp[u][v] = sz[v] * (n - sz[y]);
    dp[u][v] += max(dp[u][x], dp[v][y]);
    dp[v][u] = dp[u][v];
    mxa = max(mxa, dp[u][v]);
    return;
  }
  int x = par[0][v];
  int y = par[0][u];
  dp[u][v] = sz[u] * sz[v];
  dp[u][v] += max(dp[u][x], dp[v][y]);
  dp[v][u] = dp[u][v];
  mxa = max(mxa, dp[u][v]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(9);
  cin >> n;
  for (int i = 0; i < n + 5; ++i) sz[i] = 1;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v), G[v].push_back(u);
  }
  dfs(0);
  for (int i = 1; i < MXX; ++i)
    for (int t = 0; t < n; ++t) par[i][t] = par[i - 1][par[i - 1][t]];
  vector<pair<int, pair<int, int>>> ord;
  for (int i = 0; i < n; ++i)
    for (int t = i + 1; t < n; ++t)
      ord.push_back(make_pair(dis(i, t), make_pair(i, t)));
  sort(ord.begin(), ord.end());
  for (auto x : ord) lca(x.second.first, x.second.second);
  cout << mxa << "\n";
  return 0;
}
