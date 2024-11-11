#include <bits/stdc++.h>
using namespace std;
struct eg {
  int u, v, w, id;
  bool operator<(const eg &a) const { return w < a.w; }
} e[200001 << 1], g[200001];
int n, m, tot;
int d[200001], fa[19][200001], mx[19][200001], mi[19][200001];
int last[200001], nxt[200001 << 1], ans[200001], b[200001];
void add(int u, int v, int w) {
  e[++tot].v = v, e[tot].w = w;
  nxt[tot] = last[u];
  last[u] = tot;
}
int find(int x) { return fa[0][x] == x ? fa[0][x] : fa[0][x] = find(fa[0][x]); }
void dfs(int u) {
  for (int i = last[u]; i; i = nxt[i]) {
    int v = e[i].v;
    if (v == fa[0][u]) continue;
    fa[0][v] = u;
    mx[0][u] = e[i].w;
    d[v] = d[u] + 1;
    dfs(v);
  }
}
int lca(int u, int v, int w) {
  int res = 0;
  if (d[u] < d[v]) swap(u, v);
  for (int i = 18; i >= 0; i--)
    if (d[fa[i][u]] >= d[v])
      res = max(res, mx[i][u]), mi[i][u] = min(mi[i][u], w), u = fa[i][u];
  if (u == v) return res;
  for (int i = 18; u != v && i >= 0; i--)
    if (fa[i][u] != fa[i][v]) {
      res = max(res, mx[i][u]), res = max(res, mx[i][v]);
      mi[i][u] = min(mi[i][u], w), mi[i][v] = min(mi[i][v], w);
      u = fa[i][u], v = fa[i][v];
    }
  res = max(res, mx[0][u]), res = max(res, mx[0][v]);
  mi[0][u] = min(mi[0][u], w), mi[0][v] = min(mi[0][v], w);
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &g[i].u, &g[i].v, &g[i].w);
    g[i].id = i;
  }
  sort(g + 1, g + m + 1);
  for (int i = 1; i <= n; i++) fa[0][i] = i;
  for (int i = 1; i <= m; i++) {
    int u = find(g[i].u), v = find(g[i].v);
    if (u != v)
      fa[0][u] = v, b[i] = 1, add(g[i].u, g[i].v, g[i].w),
      add(g[i].v, g[i].u, g[i].w);
  }
  fa[0][0] = fa[0][1] = 0;
  dfs(1);
  memset(mi, 127, sizeof(mi));
  for (int i = 1; i <= 18; i++)
    for (int j = 1; j <= n; j++)
      fa[i][j] = fa[i - 1][fa[i - 1][j]],
      mx[i][j] = max(mx[i - 1][j], mx[i - 1][fa[i - 1][j]]);
  for (int i = 1; i <= m; i++)
    if (!b[i]) ans[g[i].id] = lca(g[i].u, g[i].v, g[i].w - 1) - 1;
  for (int i = 18; i; i--)
    for (int j = 1; j <= n; j++)
      mi[i - 1][j] = min(mi[i][j], mi[i - 1][j]),
             mi[i - 1][fa[i - 1][j]] = min(mi[i][j], mi[i - 1][fa[i - 1][j]]);
  for (int i = 1; i <= m; i++)
    if (b[i]) {
      int u = g[i].u, v = g[i].v;
      ans[g[i].id] = (fa[0][u] == v) ? mi[0][u] : mi[0][v];
    }
  for (int i = 1; i <= m; i++)
    printf("%d ", ans[i] >= 1000000001 ? -1 : ans[i]);
  printf("\n");
  return 0;
}
