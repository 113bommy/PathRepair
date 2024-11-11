#include <bits/stdc++.h>
int n, m;
int x[1111111], y[1111111], l[1111111];
int o[1111111];
std::vector<int> v[1111111];
struct Segt {
  int mx[4111111][2], r[4111111];
  void push(int p) { std::swap(mx[p][0], mx[p][1]), r[p] ^= 1; }
  void pushd(int p) {
    if (r[p]) push(p << 1), push(p << 1 | 1), r[p] = 0;
  }
  void pushu(int p) {
    mx[p][0] = std::max(mx[p << 1][0], mx[p << 1 | 1][0]),
    mx[p][1] = std::max(mx[p << 1][1], mx[p << 1 | 1][1]);
  }
  void accord(int* v, int p = 1, int l = 1, int r = n) {
    if (l == r) {
      mx[p][0] = v[l];
      return;
    }
    int mp = (l + r) >> 1;
    pushd(p), accord(v, p << 1, l, mp), accord(v, p << 1 | 1, mp + 1, r),
        pushu(p);
  }
  void rev(int l, int r, int p = 1, int pl = 1, int pr = n) {
    if (l > pr || pl > r) return;
    if (l <= pl && pr <= r) return push(p);
    int mp = (pl + pr) >> 1;
    pushd(p), rev(l, r, p << 1, pl, mp), rev(l, r, p << 1 | 1, mp + 1, pr),
        pushu(p);
  }
};
struct __DFN {
  Segt T;
  int dfn[1111111], dfr[1111111], fa[1111111], dep, len[1111111], rel[1111111];
  void init(int p, int f = 0) {
    dfn[p] = ++dep, fa[p] = f, rel[dep] = len[p] = len[f] + 1;
    for (int t : v[p])
      if (t ^ f) init(t, p);
    dfr[p] = dep;
  }
  void reverse(int x, int y) {
    if (fa[y] == x) x = y;
    T.rev(dfn[x], dfr[x]);
  }
  void build(int px) {
    init(px), T.accord(rel);
    register int i;
    for (i = 1; i < n; i++)
      if (l[i]) reverse(x[i], y[i]);
  }
} Rol, Ror;
int dis[1111111];
void dfs(int p = 1, int f = 0) {
  dis[p] = dis[f] + 1;
  for (int t : v[p])
    if (t ^ f) dfs(t, p);
}
void precalc() {
  dfs();
  register int i;
  int mx = -1, mp = 1;
  for (i = 1; i <= n; i++)
    if (dis[i] > mx) mx = dis[i], mp = i;
  dfs(mp), Rol.build(mp);
  for (i = 1, mx = -1, mp = 1; i <= n; i++)
    if (dis[i] > mx) mx = dis[i], mp = i;
  Ror.build(mp);
}
void revall(int x, int y) { Rol.reverse(x, y), Ror.reverse(x, y); }
void exec() {
  scanf("%d", &n);
  register int i;
  for (i = 1; i < n; i++)
    scanf("%d%d%d", x + i, y + i, l + i), v[x[i]].push_back(y[i]),
        v[y[i]].push_back(x[i]);
  precalc();
  scanf("%d", &m);
  for (i = 1; i <= m; i++)
    scanf("%d", o + i), revall(x[o[i]], y[o[i]]),
        printf("%d\n", std::max(Rol.T.mx[1][0], Ror.T.mx[1][0]) - 1);
  return;
}
int main() {
  int T = 1;
  for (; T--;) exec();
}
