#include <bits/stdc++.h>
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * f;
}
int n, m;
int first[100100], nxt[100100 << 1], to[100100 << 1], num;
inline void add(int u, int v) {
  nxt[++num] = first[u];
  to[num] = v;
  first[u] = num;
}
int f[20][100100], size[100100], dep[100100];
long long g1[100100], g2[100100];
void dfs1(int u) {
  for (register int i = 1; i <= 16; ++i) f[i][u] = f[i - 1][f[i - 1][u]];
  for (register int i = first[u], v; i; i = nxt[i]) {
    v = to[i];
    if (dep[v]) continue;
    f[0][v] = u;
    dep[v] = dep[u] + 1;
    dfs1(v);
    size[u] += size[v];
    g1[u] += g1[v];
  }
  g1[u] += size[u];
  ++size[u];
}
void dfs2(int u) {
  for (register int i = first[u], v; i; i = nxt[i]) {
    v = to[i];
    if (g2[v]) continue;
    g2[v] = g2[u] + n - size[v] * 2;
    dfs2(v);
  }
}
inline int lca(int x, int y) {
  for (register int i = 16; i >= 0; --i)
    if (dep[f[i][x]] >= dep[y]) x = f[i][x];
  if (x == y) return y;
  for (register int i = 16; i >= 0; --i)
    if (f[i][x] != f[i][y]) x = f[i][x], y = f[i][y];
  return f[0][x];
}
inline void find(int &x, int y) {
  for (register int i = 16; i >= 0; --i)
    if (dep[f[i][x]] > dep[y]) x = f[i][x];
}
int main() {
  n = read(), m = read();
  int x, y;
  for (register int i = 1; i < n; ++i) {
    x = read(), y = read();
    add(x, y), add(y, x);
  }
  dep[1] = 1;
  dfs1(1);
  g2[1] = g1[1];
  dfs2(1);
  double res;
  while (m--) {
    x = read(), y = read();
    if (dep[x] < dep[y]) std::swap(x, y);
    int fa = lca(x, y);
    res = dep[x] + dep[y] - (dep[fa] << 1);
    if (fa != y)
      printf("%.8lf\n",
             res + 1.0 * g1[x] / size[x] + 1.0 * g1[y] / size[y] + 1);
    else {
      int fx = x;
      find(fx, y);
      printf("%.8lf\n", res + 1.0 * g1[x] / size[x] +
                            1.0 * (g2[y] - g1[fx] - size[fx]) / (n - size[fx]) +
                            1);
    }
  }
  return 0;
}
