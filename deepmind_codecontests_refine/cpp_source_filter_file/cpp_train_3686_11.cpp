#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
const int inf = -1u / 4;
const int sub = 1;
int n, m;
int d[MAX_N];
vector<int> adj[MAX_N];
int p[20][MAX_N];
int lv[MAX_N];
int c[MAX_N], z[MAX_N];
queue<int> q;
inline void dfs(int u, int par) {
  p[0][u] = par;
  lv[u] = lv[par] + 1;
  for (int i = 0; i < adj[u].size(); i++) {
    if (adj[u][i] != par) {
      dfs(adj[u][i], u);
    }
  }
}
inline void bfs() {
  while (not q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
}
inline int lca(int u, int v) {
  if (lv[u] < lv[v]) {
    return lca(v, u);
  }
  for (int k = 19; k >= 0; k--) {
    if (lv[p[k][u]] >= lv[v]) {
      u = p[k][u];
    }
  }
  if (u == v) {
    return u;
  }
  for (int k = 19; k >= 0; k--) {
    if (p[k][u] != p[k][v]) {
      u = p[k][u];
      v = p[k][v];
    }
  }
  return p[0][u];
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 2; i <= n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    d[i] = inf;
  }
  dfs(1, 1);
  for (int k = 1; k < 20; k++) {
    for (int i = 1; i <= n; i++) {
      p[k][i] = p[k - 1][p[k - 1][i]];
    }
  }
  q.push(1);
  bfs();
  for (int i = 0; i < m; i++) {
    if (i % sub == 0) {
      for (int j = i - 1; j > 0; j--) {
        if (c[j] == 1) {
          d[z[j]] = 0;
          q.push(z[j]);
        }
        if (j % sub == 0) break;
      }
      bfs();
    }
    scanf("%d %d", &c[i], &z[i]);
    if (c[i] == 2) {
      int ans = d[z[i]];
      for (int j = i; j > 0; j--) {
        if (c[j] == 1) {
          ans = min(ans, lv[z[i]] + lv[z[j]] - 2 * lv[lca(z[i], z[j])]);
        }
        if (j % sub == 0) break;
      }
      printf("%d\n", ans);
    }
  }
}
