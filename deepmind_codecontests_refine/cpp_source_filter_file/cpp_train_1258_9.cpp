#include <bits/stdc++.h>
using namespace std;
struct edge {
  int v = 0;
  long long cost = 0;
  edge(int v_ = 0, int cost_ = 0) {
    v = v_;
    cost = cost_;
  }
};
vector<edge> adj[(int)(3e5 + 10)];
int n, q, p[20][(int)(3e5 + 10)], lev[(int)(3e5 + 10)];
long long ver[(int)(3e5 + 10)], dp_down[(int)(3e5 + 10)],
    dp_up[(int)(3e5 + 10)];
long long dp[20][(int)(3e5 + 10)], cost[(int)(3e5 + 10)];
int lca(int v, int u) {
  for (int i = 20 - 1; ~i; i--)
    if (lev[p[i][u]] >= lev[v]) u = p[i][u];
  if (v == u) return v;
  for (int i = 20 - 1; ~i; i--)
    if (p[i][v] != p[i][u]) {
      v = p[i][v];
      u = p[i][u];
    }
  return p[0][v];
}
int get(int v, int l) {
  long long res = dp_down[v];
  for (int i = 0; i < 20; i++)
    if (l & (1 << i)) {
      res += dp[i][v];
      v = p[i][v];
    }
  return res;
}
int pedar(int v, int l) {
  for (int i = 0; i < 20; i++)
    if (l & (1 << i)) v = p[i][v];
  return v;
}
void dfs_down(int v, int par = 0) {
  dp_down[v] = ver[v];
  p[0][v] = par;
  lev[v] = lev[par] + 1;
  for (auto e : adj[v])
    if (par ^ e.v) {
      cost[e.v] = e.cost;
      dfs_down(e.v, v);
      if ((dp_down[e.v] - 2 * e.cost) > 0)
        dp_down[v] += dp_down[e.v] - 2 * e.cost;
    }
}
void dfs_up(int v, int par = 0, long long up = 0) {
  dp_up[v] = up + ver[v];
  long long local =
      max(0ll, dp_down[v] - ver[v]) + max(0ll, dp_up[v] - ver[v]) + ver[v];
  for (auto e : adj[v])
    if (par ^ e.v)
      dfs_up(
          e.v, v,
          max(0ll, local - max(0ll, dp_down[e.v] - 2 * e.cost) - 2 * e.cost));
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> ver[i];
  for (int i = 1; i < n; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[v].push_back(edge(u, c));
    adj[u].push_back(edge(v, c));
  }
  dfs_down(1);
  dfs_up(1);
  for (int i = 2; i <= n; i++) {
    dp[0][i] = dp_down[p[0][i]] - cost[i] - max(0ll, dp_down[i] - 2 * cost[i]);
  }
  for (int i = 1; i < 20; i++) {
    for (int v = 1, papa = p[i - 1][1]; v <= n; v++, papa = p[i - 1][v]) {
      p[i][v] = p[i - 1][papa];
      if (lev[v] <= (1 << i)) continue;
      dp[i][v] = dp[i - 1][v] + dp[i - 1][papa];
    }
  }
  while (q--) {
    int v, u;
    cin >> v >> u;
    if (lev[v] > lev[u]) swap(v, u);
    int LCA = lca(v, u);
    if (LCA == v) {
      cout << get(u, lev[u] - lev[v]) + max(0ll, dp_up[v] - ver[v]) << '\n';
    } else {
      long long res =
          get(v, lev[v] - lev[LCA] - 1) + get(u, lev[u] - lev[LCA] - 1);
      res += dp_up[LCA] + dp_down[LCA] - ver[LCA];
      v = pedar(v, lev[v] - lev[LCA] - 1);
      u = pedar(u, lev[u] - lev[LCA] - 1);
      res -= cost[v] + cost[u];
      res -= max(0ll, (dp_down[v] - 2 * cost[v])) +
             max(0ll, (dp_down[u] - 2 * cost[u]));
      cout << res << '\n';
    }
  }
  return 0;
}
