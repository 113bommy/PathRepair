#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
const int mx = 1e5 + 123;
int P[mx][30], parent[mx], level[mx], sz[mx];
vector<int> adj[mx];
inline int dfs_for_LCA(int u, int lev) {
  sz[u] = 1;
  level[u] = lev;
  for (auto v : adj[u]) {
    if (v != parent[u]) {
      parent[v] = u;
      sz[u] += dfs_for_LCA(v, lev + 1);
    }
  }
  return sz[u];
}
inline void preprocess(int n) {
  memset(P, -1, sizeof(P));
  for (int i = 1; i <= n; i++) P[i][0] = parent[i];
  for (int j = 0; (1 << j) <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (P[i][j - 1] != -1) {
        P[i][j] = P[P[i][j - 1]][j - 1];
      }
    }
  }
}
inline int LCA(int u, int v) {
  if (level[u] < level[v]) swap(u, v);
  int dist = level[u] - level[v];
  while (dist > 0) {
    int rise = log2(dist);
    u = P[u][rise];
    dist -= (1 << rise);
  }
  if (u == v) return u;
  for (int j = 20; j >= 0; j--) {
    if (P[u][j] != P[v][j] && P[u][j] != -1) {
      u = P[u][j];
      v = P[v][j];
    }
  }
  return parent[u];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, u, v, m;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs_for_LCA(1, 0);
  preprocess(n);
  cin >> m;
  while (m--) {
    cin >> u >> v;
    int lca = LCA(u, v);
    if (u == v)
      cout << 1 << endl;
    else if (level[u] == level[v]) {
      int dist_u = level[u] - level[lca] - 1;
      int dist_v = level[v] - level[lca] - 1;
      int r_u = u, r_v = v;
      while (dist_u > 0) {
        int rise = log2(dist_u);
        r_u = P[r_u][rise];
        dist_u -= (1 << rise);
      }
      while (dist_v > 0) {
        int rise = log2(dist_v);
        r_v = P[r_v][rise];
        dist_v -= (1 << rise);
      }
      cout << n - sz[r_u] - sz[r_v] << endl;
    } else {
      int dist_u = level[u] - level[lca];
      int dist_v = level[v] - level[lca];
      if ((dist_u + dist_v) % 2)
        cout << 0 << endl;
      else {
        if (dist_v < dist_u) {
          swap(dist_u, dist_v);
          swap(u, v);
        }
        u = v;
        int dist = (dist_u + dist_v) >> 1;
        int tmp = dist;
        while (dist > 0) {
          int rise = log2(dist);
          u = P[u][rise];
          dist -= (1 << rise);
        }
        dist = tmp - 1;
        while (dist > 0) {
          int rise = log2(dist);
          v = P[v][rise];
          dist -= (1 << rise);
        }
        cout << sz[u] - sz[v] << endl;
      }
    }
  }
  return 0;
}
