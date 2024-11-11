#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> a, vis, edges;
vector<vector<pair<int, int>>> g;
int dfs(int u) {
  vis[u] = 1;
  int s = a[u];
  for (auto [v, e] : g[u]) {
    if (vis[v]) continue;
    int dir = 1;
    if (e < 0) dir = -1, e = -e;
    e--;
    edges[e] = dfs(v);
    s += edges[e];
    edges[e] *= dir;
    vis[u] += vis[v];
  }
  return s;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n;
  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (accumulate(a.begin(), a.end(), 0) != 0) return cout << "Impossible", 0;
  int m;
  cin >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v, (i + 1));
    g[v].emplace_back(u, -(i + 1));
  }
  vis.resize(n + 1);
  edges.resize(m);
  dfs(1);
  cout << "Possible\n";
  for (auto f : edges) cout << f << '\n';
}
