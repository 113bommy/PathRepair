#include <bits/stdc++.h>
using namespace std;
const int LOG = 20;
const int N = 100010;
struct Query {
  int id, x;
  Query() {}
  Query(int id, int x) : id(id), x(x) {}
};
vector<Query> Q[N];
vector<int> V[N];
inline void in(int &x) {
  x = 0;
  char c = getchar();
  while (c < 48 || c > 57) c = getchar();
  while (c >= 48 && c <= 57) {
    x = x * 10 + c - 48;
    c = getchar();
  }
}
int n, m, q;
int t[N], x[N], y[N], ans[N], f[N];
int find(int X) {
  int Y = X;
  for (; X != f[X]; X = f[X])
    ;
  return f[Y] = X;
}
bool mk[N];
int parent[LOG][N];
int depth[N];
void dfs(int x, int p, int d) {
  parent[0][x] = p;
  depth[x] = d;
  for (int i = 0; i < V[x].size(); i++) {
    if (V[x][i] != p) dfs(V[x][i], x, d + 1);
  }
}
void init() {
  for (int i = 1; i <= n; i++) {
    if (mk[i]) {
      V[0].push_back(i);
    }
  }
  dfs(0, -1, 0);
  for (int k = 0; k + 1 < LOG; k++) {
    for (int i = 0; i <= n; i++) {
      if (parent[k][i] < 0)
        parent[k + 1][i] = -1;
      else
        parent[k + 1][i] = parent[k][parent[k][i]];
    }
  }
}
int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < LOG; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if (u == v) return u;
  for (int k = LOG - 1; k >= 0; k--) {
    if (parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}
int main() {
  in(n);
  in(m);
  q = 0;
  int c = 0;
  for (int i = 1; i <= n; i++) mk[i] = 1;
  for (int i = 0; i < m; i++) {
    in(t[i]);
    in(x[i]);
    if (t[i] != 2)
      in(y[i]);
    else
      y[i] = ++c;
    if (t[i] == 1) {
      V[y[i]].push_back(x[i]);
      mk[x[i]] = 0;
    } else if (t[i] == 3) {
      Q[y[i]].push_back(Query(++q, x[i]));
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
  init();
  for (int i = 0; i < m; i++) {
    if (t[i] == 1) {
      f[x[i]] = y[i];
    } else if (t[i] == 2) {
      int p = find(x[i]);
      for (int j = 0; j < Q[y[i]].size(); j++) {
        Query &qu = Q[y[i]][j];
        int k = find(qu.x);
        if (k != p || lca(qu.x, qu.x) != qu.x) {
          ans[qu.id] = 0;
        } else {
          ans[qu.id] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= q; i++) puts(ans[i] ? "YES" : "NO");
  return 0;
}
