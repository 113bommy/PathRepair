#include <bits/stdc++.h>
int n, m, col[400010];
long long ans, res[400010];
namespace Qtree6 {
namespace LCT {
int sz[400010], sz2[400010], f[400010], s[400010][2];
long long size2[400010];
inline void pushup(int const &x) {
  sz[x] = 1 + sz[s[x][0]] + sz[s[x][1]] + sz2[x];
}
inline bool isroot(int const &x) { return s[f[x]][0] != x && s[f[x]][1] != x; }
inline void rotate(int const &x) {
  int y = f[x], z = f[y], k = s[y][1] == x;
  if (!isroot(y)) s[z][s[z][1] == y] = x;
  f[x] = z, f[y] = x, f[s[x][k ^ 1]] = y, s[y][k] = s[x][k ^ 1],
  s[x][k ^ 1] = y, pushup(y), pushup(x);
}
inline void splay(int const &x) {
  while (!isroot(x)) {
    if (!isroot(f[x]))
      rotate((s[f[x]][0] == x) ^ (s[f[f[x]]][0] == f[x]) ? x : f[x]);
    rotate(x);
  }
  pushup(x);
}
inline void access(int x) {
  for (int y = 0; x; y = x, x = f[x])
    splay(x), sz2[x] += sz[s[x][1]] - sz[y],
        size2[x] += 1ll * sz[s[x][1]] * sz[s[x][1]] - 1ll * sz[y] * sz[y],
        s[x][1] = y, pushup(x);
}
inline int findroot(int x) {
  access(x), splay(x);
  while (s[x][0]) x = s[x][0];
  splay(x);
  return x;
}
inline void cut(int const &x, int const &y) {
  access(y), splay(x), s[x][1] = f[y] = 0, pushup(x);
}
inline void link(int const &x, int const &y) {
  splay(x), f[x] = y, access(y), splay(y), sz2[y] += sz[x],
            size2[y] += 1ll * sz[x] * sz[x], pushup(x);
}
}  // namespace LCT
std::vector<int> v[400010];
int book[400010], f[400010];
void dfs(int const &x, int const &fa) {
  book[x] = 1, f[x] = fa;
  for (auto const &to : v[x])
    if (to != fa) dfs(to, x);
}
inline void init() {
  for (int i = 1, x, y; i < n; i++)
    scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);
  v[n + 1].push_back(1), dfs(n + 1, 0);
  for (int i = 1; i <= n; i++) LCT::link(i, f[i]);
}
inline void rev(int const &u) {
  if (book[u])
    LCT::cut(f[u], u);
  else
    LCT::link(u, f[u]);
  book[u] ^= 1;
}
inline int query(int const &u) {
  int op = LCT::findroot(u);
  return LCT::sz[op] - LCT::sz2[op] - 1;
}
inline long long query2(int const &u) {
  LCT::access(u);
  return LCT::size2[u];
}
}  // namespace Qtree6
std::vector<std::tuple<int, int, int>> q[400010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", col + i), q[col[i]].emplace_back(i, 1, 0);
  Qtree6::init();
  for (int i = 1, a, b; i <= m; i++) {
    scanf("%d%d", &a, &b);
    q[col[a]].emplace_back(a, 0, i);
    q[col[a] = b].emplace_back(a, 1, i);
  }
  int v, c, t, p, d;
  long long e;
  for (int i = 1; i <= n; i++) {
    ans = 0;
    for (auto &&tp : q[i]) {
      std::tie(v, c, t) = tp;
      res[t] -= ans;
      if (c == 1) {
        p = Qtree6::query(v);
        ans += 1ll * p * p;
        Qtree6::rev(v);
        d = Qtree6::query(Qtree6::f[v]);
        e = Qtree6::query2(v);
        ans -= 1ll * d * d + e;
      } else {
        p = Qtree6::query(Qtree6::f[v]);
        e = Qtree6::query2(v);
        ans += 1ll * p * p + e;
        Qtree6::rev(v);
        d = Qtree6::query(v);
        ans -= 1ll * d * d;
      }
      res[t] += ans;
    }
    for (auto &&tp : q[i]) Qtree6::rev(std::get<0>(tp));
  }
  for (int i = 1; i <= m; i++) res[i] += res[i - 1];
  for (int i = 0; i <= m; i++) printf("%lld\n", res[i]);
  return 0;
}
