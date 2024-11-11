#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct Edge {
  int u, v, w, id;
  bool operator<(const Edge &e) const { return w < e.w; }
} e[N];
int n, m, l, fw[N], ans[N], rt[N], d[N], f[N][19], g[N][19];
bool tag[N];
struct linke {
  int v, nxt;
} G[N * 2];
int hd[N], ec;
void link(int u, int v) {
  G[++ec] = (linke){v, hd[u]};
  hd[u] = ec;
}
int find(int u) { return u == rt[u] ? u : rt[u] = find(rt[u]); }
void lca(int u, int v, int &x, int &ma) {
  if (d[u] < d[v]) swap(u, v);
  int c = d[u] - d[v];
  ma = 0;
  for (int i = l; i >= 0; i--)
    if (c >> i & 1) {
      ma = max(ma, g[u][i]);
      u = f[u][i];
    }
  if (u == v) {
    x = u;
    return;
  }
  for (int i = l; i >= 0; i--) {
    if (f[u][i] != f[v][i]) {
      ma = max(ma, max(g[u][i], g[v][i]));
      u = f[u][i];
      v = f[v][i];
    }
  }
  x = f[u][0];
  ma = max(ma, max(g[u][0], g[v][0]));
}
void dfs(int u, int fa = 0) {
  f[u][0] = fa;
  d[u] = d[fa] + 1;
  for (int i = 1; i <= l; i++) {
    f[u][i] = f[f[u][i - 1]][i - 1];
    g[u][i] = max(g[u][i - 1], g[f[u][i - 1]][i - 1]);
  }
  for (int i = hd[u]; i; i = G[i].nxt) {
    int id = G[i].v;
    int v = e[id].u ^ e[id].v ^ u;
    if (v == fa) continue;
    g[v][0] = e[id].w;
    dfs(v, u);
  }
}
struct emt {
  int v, de;
  bool operator<(const emt &b) const { return v < b.v; }
};
struct lpt {
  emt v;
  int l, r, d;
} po[N];
int r[N], psz;
int merge(int u, int v) {
  if (!u || !v) return u | v;
  if (po[v].v < po[u].v) swap(u, v);
  po[u].r = merge(po[u].r, v);
  if (po[po[u].l].d < po[po[u].r].d) swap(po[u].l, po[u].r);
  po[u].d = po[po[u].r].d + 1;
  return u;
}
void insert(int u, const emt &x) {
  po[++psz] = (lpt){x, 0, 0, 0};
  r[u] = merge(r[u], psz);
}
emt top(int u) { return po[r[u]].v; }
void pop(int u) { r[u] = merge(po[r[u]].l, po[r[u]].r); }
void dfs2(int u, int fa = 0) {
  for (int i = hd[u]; i; i = G[i].nxt) {
    int id = G[i].v;
    int v = e[id].u ^ e[id].v ^ u;
    if (v == fa) continue;
    fw[v] = e[id].id;
    dfs2(v, u);
    r[u] = merge(r[u], r[v]);
  }
  if (fw[u]) {
    while (r[u] && top(u).de >= d[u]) pop(u);
    if (r[u]) {
      ans[fw[u]] = top(u).v - 1;
    } else
      ans[fw[u]] = -1;
  }
}
int main() {
  po[0].d = 0;
  scanf("%d%d", &n, &m);
  for (l = 1; (1 << l) <= n; l++)
    ;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    e[i].id = i;
  }
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= n; i++) rt[i] = i;
  for (int i = 1; i <= m; i++) {
    int u = find(e[i].u), v = find(e[i].v);
    if (u != v) {
      tag[e[i].id] = 1;
      link(e[i].u, i);
      link(e[i].v, i);
      rt[v] = u;
    }
  }
  dfs(1);
  for (int x, w, i = 1; i <= m; i++)
    if (!tag[e[i].id]) {
      lca(e[i].u, e[i].v, x, w);
      insert(e[i].u, (emt){e[i].w, d[x]});
      insert(e[i].v, (emt){e[i].w, d[x]});
      ans[e[i].id] = w - 1;
    }
  dfs2(1);
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  return 0;
}
