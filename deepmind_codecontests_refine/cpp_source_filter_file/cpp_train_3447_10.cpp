#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> G[MAXN];
int f[MAXN][25], g[MAXN][25], lv[MAXN], st[MAXN];
int n, p, q, l, r;
void dfs(int u) {
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
  if (u == 0 || v == 0 || u > n || v > n) return 0;
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
    for (int i = s; i < t; i++) st[i] = j;
  }
}
int query(int a, int b) {
  if (a == b) return a;
  int l = st[b - a];
  return lca(g[a][l], g[b - (1 << l)][l]);
}
int max_lv = -1, cs = -1;
void calc(int u, int a, int b) {
  while (a < b) {
    int m = (a + b) >> 1;
    int cu = query(a, m), cv = query(m + 1, b);
    int x = lca(u, cu), y = lca(u, cv);
    if (lv[x] <= lv[y])
      u = y, b = m;
    else
      u = x, a = m + 1;
  }
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
  for (int i = 1; i < n; i++) g[i][0] = lca(i, i + 1);
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i + (1 << (j - 1)) <= n; i++) {
      g[i][j] = lca(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &l, &r);
    int m = (l + r) >> 1;
    int u = query(l, m), v = query(m + 1, r);
    if (u == v)
      printf("%d %d\n", l, lv[u]);
    else {
      max_lv = -1, cs = -1;
      calc(u, m + 1, r);
      calc(v, l, m);
      printf("%d %d\n", cs, max_lv);
    }
  }
  return 0;
}
