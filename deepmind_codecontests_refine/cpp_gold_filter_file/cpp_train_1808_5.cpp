#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void ckmin(T &a, U b) {
  if (a > b) a = b;
}
template <class T, class U>
void ckmax(T &a, U b) {
  if (a < b) a = b;
}
int N, M, Q, T, C, R;
vector<int> edge[200013], edge1[200013];
vector<int> bcc[200013];
int siz[200013];
int st[200013], ft[200013];
int dp[200013], parent[200013], depth[200013];
int id[200013];
int pw2[200013];
vector<pair<int, int> > edges;
int ancestor[20][200013];
bitset<200013> seen;
bitset<200013> ok;
void dfs(int u, int p) {
  st[u] = ft[u] = T;
  T++;
  seen[u] = true;
  for (int v : edge[u]) {
    if (v == p) continue;
    if (seen[v]) {
      if (st[v] > st[u]) continue;
      edges.push_back({u, v});
      ckmin(ft[u], st[v]);
      continue;
    }
    edges.push_back({u, v});
    dfs(v, u);
    ckmin(ft[u], ft[v]);
    if (ft[v] >= st[u]) {
      while (!edges.empty()) {
        pair<int, int> p = edges.back();
        edges.pop_back();
        bcc[p.first].push_back(C);
        bcc[p.second].push_back(C);
        if (p == make_pair(u, v)) break;
      }
      C++;
    }
  }
}
void dfs1(int u, int p) {
  for (int v : edge1[u]) {
    if (v == p) continue;
    depth[v] = depth[u] + 1;
    parent[v] = u;
    dp[v] = dp[u] + ok[v];
    dfs1(v, u);
  }
  return;
}
int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (auto i = (20) - 1; i >= (0); i--) {
    if ((depth[v] - depth[u]) >= (1 << i)) {
      v = ancestor[i][v];
    }
  }
  if (u == v) return u;
  for (auto i = (20) - 1; i >= (0); i--) {
    if (ancestor[i][u] != ancestor[i][v]) {
      u = ancestor[i][u];
      v = ancestor[i][v];
    }
  }
  return parent[u];
}
int32_t main() {
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(4);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (auto i = (0); i < (M); i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(0, N);
  for (auto i = (0); i < (N); i++) {
    sort((bcc[i]).begin(), (bcc[i]).end());
    bcc[i].erase(unique((bcc[i]).begin(), (bcc[i]).end()), bcc[i].end());
    for (int x : bcc[i]) {
      siz[x]++;
    }
  }
  for (auto i = (0); i < (C); i++) {
    if (siz[i] > 2) ok[i] = true;
  }
  for (auto i = (0); i < (N); i++) {
    id[i] = -1;
    for (int x : bcc[i]) {
      if (siz[x] > 2) {
        id[i] = x;
        R = x;
      }
    }
    if (id[i] == -1) {
      id[i] = C;
      R = C;
      C++;
    }
  }
  dp[R] = ok[R];
  for (auto i = (0); i < (N); i++) {
    for (int v : edge[i]) {
      if (id[i] != id[v]) {
        edge1[id[i]].push_back(id[v]);
      }
    }
  }
  parent[R] = C;
  dfs1(R, C);
  for (auto i = (0); i < (20); i++) {
    ancestor[i][C] = C;
  }
  for (auto j = (0); j < (C); j++) {
    ancestor[0][j] = parent[j];
  }
  for (auto i = (1); i < (20); i++) {
    for (auto j = (0); j < (C); j++) {
      ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
    }
  }
  pw2[0] = 1;
  for (auto i = (1); i < (N + 1); i++) {
    pw2[i] = pw2[i - 1] + pw2[i - 1];
    if (pw2[i] >= 1000000007) pw2[i] -= 1000000007;
  }
  cin >> Q;
  while (Q--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    u = id[u];
    v = id[v];
    int w = lca(u, v);
    int ans = dp[u] + dp[v] - 2 * dp[w];
    if (ok[w]) ans++;
    ans = pw2[ans];
    cout << ans << '\n';
  }
  return 0;
}
