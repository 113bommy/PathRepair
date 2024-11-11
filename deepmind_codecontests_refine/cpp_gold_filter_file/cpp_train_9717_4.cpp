#include <bits/stdc++.h>
typedef struct {
  int f, t, i;
} edge;
int cmp(edge a, edge b) { return a.f < b.f; }
edge oe[200200], se[200200];
int of[100100], sf[100100], vis[100100], low[100100], vt, dad[100100];
int isbr[100100];
void dfs(edge* e, int* f, int w) {
  vis[w] = low[w] = vt++;
  for (int i = f[w - 1]; i < f[w]; i++) {
    if (!vis[e[i].t]) {
      dad[e[i].t] = w;
      dfs(e, f, e[i].t);
      low[w] = std::min(low[w], low[e[i].t]);
      if (low[e[i].t] > vis[w]) isbr[e[i].i] = 1;
    } else if (dad[w] != e[i].t)
      low[w] = std::min(low[w], vis[e[i].t]);
  }
}
int ds[100100];
int fi(int k) { return k == ds[k] ? k : ds[k] = fi(ds[k]); }
void un(int a, int b) { ds[fi(a)] = fi(b); }
int u[100100][20];
void dfs2(edge* e, int* f, int w, int d) {
  vis[w] = d;
  for (int i = f[w - 1]; i < f[w]; i++) {
    if (!vis[e[i].t]) {
      u[e[i].t][0] = w;
      for (int j = 1; (1 << j) < d + 1; j++)
        u[e[i].t][j] = u[u[e[i].t][j - 1]][j - 1];
      dfs2(e, f, e[i].t, d + 1);
    }
  }
}
int fly(int a, int x) {
  for (int i = 17; x; i--) {
    if (x >= (1 << i)) {
      a = u[a][i];
      x -= (1 << i);
    }
  }
  return a;
}
int lca(int a, int b) {
  if (vis[a] < vis[b]) std::swap(a, b);
  a = fly(a, vis[a] - vis[b]);
  if (a == b) return a;
  for (int i = 17; i >= 0; i--) {
    if (vis[a] - 1 >= (1 << i)) {
      if (u[a][i] != u[b][i]) {
        a = u[a][i];
        b = u[b][i];
      }
    }
  }
  return u[a][0];
}
int dis(int a, int b) {
  int m = lca(a, b);
  return vis[a] + vis[b] - 2 * vis[m];
}
int main() {
  int n, m, k;
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= n; i++) {
    of[i] = vis[i] = 0;
    ds[i] = i;
  }
  for (int i = 0, x, y; i < m; i++) {
    scanf("%d %d", &x, &y);
    of[oe[i].f = oe[i + m].t = x]++;
    of[oe[i].t = oe[i + m].f = y]++;
    isbr[oe[i].i = oe[i + m].i = i] = 0;
  }
  m = m + m;
  for (int i = 1; i <= n; i++) of[i] += of[i - 1];
  std::sort(oe, oe + m, cmp);
  vt = 1;
  dfs(oe, of, 1);
  for (int i = 0; i < m; i++) {
    if (isbr[oe[i].i] == 0) {
      un(oe[i].f, oe[i].t);
    }
  }
  int set = 0;
  for (int i = 0; i <= n; i++) sf[i] = vis[i] = 0;
  for (int i = 0; i < m; i++) {
    if (isbr[oe[i].i]) {
      se[set] = (edge){fi(oe[i].f), fi(oe[i].t), set};
      sf[se[set].f]++;
      set++;
    }
  }
  for (int i = 1; i <= n; i++) sf[i] += sf[i - 1];
  std::sort(se, se + set, cmp);
  dfs2(se, sf, fi(1), 1);
  int q;
  scanf("%d", &q);
  for (int i = 0, x, y; i < q; i++) {
    scanf("%d %d", &x, &y);
    printf("%d\n", dis(fi(x), fi(y)));
  }
  return 0;
}
