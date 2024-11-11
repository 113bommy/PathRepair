#include <bits/stdc++.h>
using namespace std;
const int N = 510000;
int n, m, K, c[N], sum[N], col[N], vis[N], valid[N], bel[N], cnt, flg;
vector<int> pot[N], G[N], E[N], stk, vec[2];
map<pair<int, int>, vector<pair<int, int> > > Map;
long long ans;
void dfs(int u, int cur) {
  vis[u] = 1, col[u] = cur;
  vec[col[u]].push_back(u);
  for (int v : E[u]) {
    if (!vis[v])
      dfs(v, cur ^ 1);
    else if (col[v] == col[u])
      flg = 0;
  }
}
void Dfs(int u, int cur) {
  vis[u] = 1, col[u] = cur;
  stk.push_back(u);
  for (int v : G[u]) {
    if (!vis[v])
      Dfs(v, cur ^ 1);
    else if (col[v] == col[u])
      flg = 0;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> K;
  for (int i = 1; i <= n; ++i) cin >> c[i], pot[c[i]].push_back(i);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    if (c[u] > c[v]) swap(u, v);
    if (c[u] == c[v])
      E[u].push_back(v), E[v].push_back(u);
    else
      Map[make_pair(c[u], c[v])].emplace_back(u, v);
  }
  int tot = 0;
  for (int i = 1; i <= K; ++i) {
    flg = 1;
    for (int x : pot[i])
      if (!vis[x]) {
        dfs(x, 0);
        ++cnt;
        for (int y : vec[0]) bel[y] = cnt;
        if (vec[1].size()) {
          ++cnt;
          for (int y : vec[1]) bel[y] = cnt;
          G[cnt].push_back(cnt - 1);
          G[cnt - 1].push_back(cnt);
        }
        vec[0].clear(), vec[1].clear();
      }
    valid[i] = flg, tot += flg;
  }
  ans += 1ll * tot * (tot - 1) / 2;
  memset(vis, 0, sizeof(vis));
  for (auto i : Map) {
    if (!valid[i.first.first] || !valid[i.first.second]) continue;
    vector<int> node;
    for (auto it : i.second) {
      int u = bel[it.first], v = bel[it.second];
      G[u].push_back(v), G[v].push_back(u);
      node.push_back(u), node.push_back(v);
    }
    flg = 1;
    for (int i = 0; i < node.size() && flg; ++i) {
      int x = node[i];
      if (vis[x]) continue;
      Dfs(x, 0);
    }
    if (!flg) --ans;
    for (auto it : stk) vis[it] = 0;
    stk.clear();
    for (auto it : i.second) {
      int u = bel[it.first], v = bel[it.second];
      G[u].pop_back(), G[v].pop_back();
    }
  }
  cout << ans;
  return 0;
}
