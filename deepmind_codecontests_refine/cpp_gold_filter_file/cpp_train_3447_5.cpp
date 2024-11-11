#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> G[MAXN];
int f[MAXN][25], g[MAXN][25], rmq_min[MAXN][25], rmq_max[MAXN][25], lv[MAXN],
    st[MAXN], dfn[MAXN], dfn_t = 0;
int n, p, q, l, r;
void dfs(int u) {
  dfn[u] = ++dfn_t;
  for (auto v : G[u]) {
    lv[v] = lv[u] + 1;
    dfs(v);
  }
}
void init_lca() {
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++) f[i][j] = f[f[i][j - 1]][j - 1];
}
int lca(int u, int v) {
  if (u == 0 || u > n) return v;
  if (v == 0 || v > n) return u;
  if (lv[u] < lv[v]) swap(u, v);
  for (int j = 20; j >= 0; j--)
    if (f[u][j] != 0 && lv[f[u][j]] >= lv[v]) u = f[u][j];
  if (u == v) return u;
  for (int j = 20; j >= 0; j--)
    if (f[u][j] != f[v][j]) u = f[u][j], v = f[v][j];
  return f[u][0];
}
void init_st() {
  for (int j = 0; j <= 20; j++) {
    int s = (1 << j), t = (1 << (j + 1));
    if (s > n) break;
    for (int i = s; i < t && i < n; i++) st[i] = j;
  }
}
void init_rmq() {
  for (int i = 1; i <= n; i++) rmq_min[i][0] = rmq_max[i][0] = dfn[i];
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i + (1 << j) <= n + 1; i++) {
      rmq_min[i][j] =
          min(rmq_min[i][j - 1], rmq_min[i + (1 << (j - 1))][j - 1]);
      rmq_max[i][j] =
          max(rmq_max[i][j - 1], rmq_max[i + (1 << (j - 1))][j - 1]);
    }
}
int query(int a, int b) {
  if (a > b) return 0;
  if (a == b) return a;
  int l = st[b - a];
  return lca(g[a][l], g[b - (1 << l)][l]);
}
int query_min(int a, int b) {
  int l = st[b - a + 1];
  return min(rmq_min[a][l], rmq_min[b - (1 << l) + 1][l]);
}
int query_max(int a, int b) {
  int l = st[b - a + 1];
  return max(rmq_max[a][l], rmq_max[b - (1 << l) + 1][l]);
}
int max_lv = -1, cs = -1;
void calc_min(int a, int b) {
  int x = a, y = b;
  while (a < b) {
    int m = (a + b) >> 1;
    if (query_min(a, m) < query_min(m + 1, b))
      b = m;
    else
      a = m + 1;
  }
  int u = lca(query(x, a - 1), query(a + 1, y));
  if (lv[u] > max_lv) {
    max_lv = lv[u];
    cs = a;
  }
}
void calc_max(int a, int b) {
  int x = a, y = b;
  while (a < b) {
    int m = (a + b) >> 1;
    if (query_max(a, m) > query_max(m + 1, b))
      b = m;
    else
      a = m + 1;
  }
  int u = lca(query(x, a - 1), query(a + 1, y));
  if (lv[u] > max_lv) {
    max_lv = lv[u];
    cs = a;
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &p);
    G[p].emplace_back(i);
    f[i][0] = p;
  }
  dfs(1);
  init_lca();
  init_st();
  init_rmq();
  for (int i = 1; i < n; i++) g[i][0] = lca(i, i + 1);
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i + (1 << (j - 1)) <= n; i++)
      g[i][j] = lca(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &l, &r);
    max_lv = -1, cs = -1;
    calc_min(l, r);
    calc_max(l, r);
    printf("%d %d\n", cs, max_lv);
  }
  return 0;
}
