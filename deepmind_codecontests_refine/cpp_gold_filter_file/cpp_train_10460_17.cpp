#include <bits/stdc++.h>
using namespace std;
vector<int> g[100001], level, no;
int par[100001][20], n;
int dfs(int vtx, int p, int l) {
  level[vtx] = l;
  par[vtx][0] = p;
  int ans = 1;
  for (int i : g[vtx]) {
    if (i != p) {
      ans += dfs(i, vtx, l + 1);
    }
  }
  no[vtx] = ans;
  return ans;
}
void make() {
  for (int j = 1; j <= log2(n); j++) {
    for (int i = 1; i <= n; i++) {
      int t = par[i][j - 1];
      par[i][j] = par[t][j - 1];
    }
  }
}
int kth_par(int u, int k) {
  while (k) {
    int t = log2(k);
    u = par[u][t];
    k -= (1 << t);
  }
  return u;
}
int lca(int u, int v) {
  if (level[u] < level[v]) swap(u, v);
  int d = level[u] - level[v];
  while (d) {
    int t = log2(d);
    u = par[u][t];
    d -= (1 << t);
  }
  if (u == v) return v;
  for (int i = log2(n); i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i], v = par[v][i];
    }
  }
  return par[u][0];
}
int distance(int u, int v) {
  return level[u] + level[v] - 2 * level[lca(u, v)];
}
int solve(int u, int v) {
  if (u == v) return n;
  if (level[u] < level[v]) swap(u, v);
  if (level[u] == level[v]) {
    int t = distance(u, lca(u, v));
    return n - no[kth_par(u, t - 1)] - no[kth_par(v, t - 1)];
  } else {
    int d = distance(u, v);
    if (d % 2) return 0;
    int lc = lca(u, v);
    if (lc == v) {
      int t = (level[u] - level[v]) / 2;
      return no[kth_par(u, t)] - no[kth_par(u, t - 1)];
    }
    return no[kth_par(u, d / 2)] - no[kth_par(u, d / 2 - 1)];
  }
}
int main() {
  cin >> n;
  level.resize(n + 1);
  no.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0, 0);
  make();
  int Q;
  cin >> Q;
  while (Q--) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << "\n";
  }
}
