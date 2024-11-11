#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005, inf = 0x3f3f3f3f;
int n, m, root, par[MAXN], f[MAXN], s[MAXN][2], sum[MAXN], w[MAXN], mi[MAXN],
    mx[MAXN];
vector<int> g[MAXN];
inline void up(int u) {
  if (!u) return;
  sum[u] = sum[s[u][0]] + sum[s[u][1]] + w[u];
  mi[u] = min(sum[s[u][0]] + w[u] + min(0, mi[s[u][1]]), mi[s[u][0]]);
  mx[u] = max(sum[s[u][0]] + w[u] + max(0, mx[s[u][1]]), mx[s[u][0]]);
}
inline bool pos(int u) { return s[f[u]][1] == u; }
inline void sets(int u, int v, int d) { f[s[u][d] = v] = u; }
inline void rotate(int v) {
  int u = f[v];
  bool d = pos(v);
  sets(u, s[v][!d], d);
  f[u] ? sets(f[u], v, pos(u)) : void(f[v] = 0);
  sets(v, u, !d);
  up(u);
}
inline void splay(int v, int goal = 0) {
  for (int u; (u = f[v]) != goal; rotate(v))
    if (f[u] != goal) rotate(pos(u) == pos(v) ? u : v);
  goal ? 0 : root = v;
  up(v);
}
inline int pre(int u) {
  splay(u);
  for (u = s[u][0]; s[u][1]; u = s[u][1])
    ;
  return u;
}
inline int suf(int u) {
  splay(u);
  for (u = s[u][1]; s[u][0]; u = s[u][0])
    ;
  return u;
}
inline int find(int u, int val) {
  if (sum[s[u][0]] + w[u] + mx[s[u][1]] >= val &&
      sum[s[u][0]] + w[u] + mi[s[u][1]] <= val)
    return find(s[u][1], val - sum[s[u][0]] - w[u]);
  if (sum[s[u][0]] + w[u] == val) return (u & 1) ? par[u >> 1] : (u >> 1);
  return find(s[u][0], val);
}
inline void dfs(int u) {
  sum[u << 1] = mx[u << 1] = mi[u << 1] = w[u << 1] = +1;
  sets(root, u << 1, 1);
  splay(u << 1);
  for (int v : g[u]) par[v] = u, dfs(v);
  sum[u << 1 | 1] = mx[u << 1 | 1] = mi[u << 1 | 1] = w[u << 1 | 1] = -1;
  sets(root, u << 1 | 1, 1);
  splay(u << 1 | 1);
}
inline int distance() {
  int u, v, du, dv, df;
  scanf("%d%d", &u, &v);
  u <<= 1;
  v <<= 1;
  splay(u);
  du = sum[s[root][0]] + w[root];
  splay(v);
  dv = sum[s[root][0]] + w[root];
  splay(u);
  splay(v, root);
  if (pos(v)) swap(u, v);
  splay(u);
  splay(v, root);
  df = min(sum[v] + w[v] + mi[s[v][1]], min(du, dv));
  return du + dv - 2 * df;
}
inline void unlock(int u) { f[u] = s[f[u]][pos(u)] = 0; }
inline int del(int u) {
  int l = pre(u << 1);
  splay(l, root);
  unlock(l);
  up(root);
  int r = suf(u << 1 | 1);
  splay(r, root);
  unlock(r);
  up(root);
  int o = root;
  if (!l || !r)
    root = l | r;
  else
    sets(root = l, r, 1), up(root);
  return o;
}
inline void change() {
  int v, h, o;
  scanf("%d%d", &v, &h);
  splay(v << 1);
  par[v] = o = find(s[v << 1][0], sum[s[v << 1][0]] + w[v << 1] - h);
  o = o << 1 | 1;
  v = del(v);
  splay(o);
  splay(pre(o), root);
  sets(s[o][0], v, 1);
  up(s[o][0]);
  up(o);
}
inline int k_depth() {
  int k;
  scanf("%d", &k);
  return find(root, ++k);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int u = 1, son; u <= n; ++u) {
    scanf("%d", &son);
    for (int v, j = 1; j <= son; ++j) {
      scanf("%d", &v);
      g[u].push_back(v);
    }
  }
  mi[0] = inf;
  mx[0] = -inf;
  dfs(1);
  for (int opt; m--;) {
    scanf("%d", &opt);
    if (opt == 1)
      printf("%d\n", distance());
    else if (opt == 2)
      change();
    else
      printf("%d\n", k_depth());
  }
  return 0;
}
