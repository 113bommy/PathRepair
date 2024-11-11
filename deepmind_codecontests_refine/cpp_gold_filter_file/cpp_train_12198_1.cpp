#include <bits/stdc++.h>
const int N = 100011, M = 1000011;
void swap(int& x, int& y) {
  int t = x;
  x = y;
  y = t;
}
int max(int x, int y) { return x > y ? x : y; }
void cmax(int& x, int y) {
  if (y > x) x = y;
}
int n, m, cnt, head[N];
struct edge {
  int to, nxt, w;
} e[N << 1];
void add(int x, int y, int w) {
  e[++cnt].to = y;
  e[cnt].nxt = head[x];
  head[x] = cnt;
  e[cnt].w = w;
}
struct EDGE {
  int x, y, w, id;
  bool operator<(const EDGE& t) const { return w < t.w; }
} E[M];
bool b[M];
int fa[N], mx[N];
int gf(int x) { return x == fa[x] ? x : (fa[x] = gf(fa[x])); }
int f[19][N], g[19][N], d[N], lca, mxe;
void dfs(int x, int fa) {
  f[0][x] = fa, d[x] = d[fa] + 1;
  for (int i = 1; i <= 18; ++i)
    f[i][x] = f[i - 1][f[i - 1][x]],
    g[i][x] = max(g[i - 1][x], g[i - 1][f[i - 1][x]]);
  for (int i = head[x], to; to = e[i].to, i; i = e[i].nxt)
    if (to != fa) g[0][to] = e[i].w, dfs(to, x);
}
void gm(int x, int y) {
  lca = -1, mxe = -1000000;
  if (d[x] < d[y]) swap(x, y);
  for (int i = 18; ~i; --i)
    if (d[f[i][x]] >= d[y]) cmax(mxe, g[i][x]), x = f[i][x];
  if (x == y) return lca = x, void();
  for (int i = 18; ~i; --i)
    if (f[i][x] != f[i][y])
      cmax(mxe, max(g[i][x], g[i][y])), x = f[i][x], y = f[i][y];
  return lca = f[0][x], cmax(mxe, max(g[0][x], g[0][y])), void();
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
    scanf("%d%d%d", &E[i].x, &E[i].y, &E[i].w), E[i].id = i;
  std::sort(E + 1, E + m + 1);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1, j = 0; j < n - 1; ++i) {
    int x = E[i].x, y = E[i].y, w = E[i].w;
    if (gf(x) != gf(y))
      b[i] = 1, fa[gf(x)] = gf(y), add(x, y, w), add(y, x, w), ++j;
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) fa[i] = i, mx[i] = 1000000000;
  static int ans[M];
  for (int i = 1; i <= m; ++i)
    if (!b[i]) {
      int x = E[i].x, y = E[i].y, w = E[i].w;
      gm(x, y);
      ans[E[i].id] = mxe;
      while (d[gf(x)] > d[lca]) mx[fa[x]] = w, fa[fa[x]] = gf(f[0][fa[x]]);
      while (d[gf(y)] > d[lca]) mx[fa[y]] = w, fa[fa[y]] = gf(f[0][fa[y]]);
    }
  for (int i = 1; i <= m; ++i)
    if (b[i]) ans[E[i].id] = mx[d[E[i].x] > d[E[i].y] ? E[i].x : E[i].y];
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
}
