#include <bits/stdc++.h>
using namespace std;
struct edge {
  int v, nt;
} G[500010 << 1];
long long s[500010], t[500010];
int n, m, q, h[500010], cnt, d[500010], f[500010], v[500010], r[500010];
int l[500010], clk, sz[500010], top[500010], son[500010], w[500010];
inline void adj(int x, int y) {
  G[++cnt] = (edge){y, h[x]};
  h[x] = cnt;
  G[++cnt] = (edge){x, h[y]};
  h[y] = cnt;
}
inline void dfs(int x, int p) {
  f[x] = p;
  d[x] = d[p] + 1;
  sz[x] = 1;
  for (int v, i = h[x]; i; i = G[i].nt)
    if (!d[v = G[i].v]) {
      dfs(v, x);
      sz[x] += sz[v];
      if (sz[v] > sz[son[x]]) son[x] = v;
    }
}
inline void dgs(int x, int p) {
  top[x] = p;
  l[x] = ++clk;
  w[clk] = x;
  if (son[x]) dgs(son[x], p);
  for (int v, i = h[x]; i; i = G[i].nt)
    if (!l[v = G[i].v]) dgs(v, v);
  r[x] = clk;
}
inline void add(int L, int R, long long v) {
  for (int x = L; x <= n; x += x & -x) s[x] += v, t[x] += v * (L - 1);
  for (int x = R + 1; x <= n; x += x & -x) s[x] -= v, t[x] -= v * R;
}
inline long long query(int L, int R, long long S = 0) {
  for (int x = L - 1; x; x &= x - 1) S += t[x] - s[x] * (L - 1);
  for (int x = R; x; x &= x - 1) S += s[x] * R - t[x];
  return S;
}
inline int swim(int x, int D) {
  for (; D > d[x] - d[top[x]]; x = f[top[x]]) D -= d[x] - d[top[x]] + 1;
  return w[l[x] - D];
}
inline int lca(int x, int y) {
  for (; top[x] != top[y]; y = f[top[y]])
    if (d[top[x]] > d[top[y]]) swap(x, y);
  return d[x] < d[y] ? x : y;
}
int main() {
  scanf("%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", v + i);
  for (int x, y, i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    adj(x, y);
  }
  dfs(1, 0);
  dgs(1, 1);
  for (int i = 1; i <= n; ++i) add(l[i], l[i], v[i]);
  int rt = 1;
  for (int o, x, y, v; m--;) {
    scanf("%d%d", &o, &x);
    if (o == 1)
      rt = x;
    else if (o == 3) {
      if (x == rt)
        printf("%lld\n", query(1, n));
      else if (l[x] < l[rt] && r[x] >= r[rt]) {
        o = swim(rt, d[rt] - d[x] - 1);
        printf("%lld\n", query(1, n) - query(l[o], r[o]));
      } else
        printf("%lld\n", query(l[x], r[x]));
    } else {
      scanf("%d%d", &y, &v);
      int p = lca(x, y);
      if (x == rt || y == rt || p == rt)
        add(1, n, v);
      else if (l[p] < l[rt] && r[p] >= r[rt]) {
        if (p == lca(x, rt)) swap(x, y);
        int g = lca(x, rt), dr = swim(rt, d[rt] - d[g] - 1);
        add(1, n, v);
        if (d[rt] - d[g] - 1 >= 0) add(l[dr], r[dr], -v);
      } else
        add(l[p], r[p], v);
    }
  }
}
