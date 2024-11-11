#include <bits/stdc++.h>
using db = double;
const int N = 100007;
const db eps = 1e-10, inf = 1e10;
int n, m, fa[N], dep[N], size[N], son[N], top[N], vis[N];
db ans = inf, t, c[N], ed[N];
struct line {
  int x, id, o;
  db t, c;
} b[N];
db cal(const line& x) { return dep[x.x] + (t - x.t) * c[x.id]; }
int operator<(const line& a, const line& b) { return cal(a) < cal(b); }
std::vector<int> e[N];
std::vector<line> f[N];
std::multiset<line> s;
int read() {
  int x = 0, c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) (x *= 10) += c & 15, c = getchar();
  return x;
}
void dfs(int u) {
  size[u] = 1;
  for (int v : e[u])
    if (v ^ fa[u])
      fa[v] = u, dep[v] = dep[u] + 1, dfs(v), size[u] += size[v],
      son[u] = size[v] > size[son[u]] ? v : son[u];
}
void dfs(int u, int tp) {
  top[u] = tp;
  if (son[u]) dfs(son[u], tp);
  for (int v : e[u])
    if (v ^ fa[u] && v ^ son[u]) dfs(v, v);
}
int lca(int u, int v) {
  for (; top[u] ^ top[v]; u = fa[top[u]])
    if (dep[top[v]] > dep[top[u]]) std::swap(u, v);
  return dep[u] > dep[v] ? v : u;
}
db cal(int u, int v, db c) { return (dep[u] - dep[v]) / c; }
void update(const line& x, const line& y) {
  db v = cal(y) - cal(x),
     p = fabs(v) < eps ? 0 : (cal(y) - cal(x)) / (c[x.id] - c[y.id]);
  if (p > -eps && p + t < std::min(ed[x.id], ed[y.id]) + eps)
    ans = std::min(ans, p + t);
}
void work(int u) {
  s.clear(),
      std::sort(f[u].begin(), f[u].end(), [](const line& a, const line& b) {
        return fabs(a.t - b.t) < eps ? a.o > b.o : a.t < b.t;
      });
  for (line x : f[u])
    if (x.o)
      b[x.id] = x;
    else
      ed[x.id] = x.t;
  for (line x : f[u]) {
    if ((t = x.t) > ans + eps) break;
    if (x.o) {
      auto it = s.insert(x);
      c[x.id] = x.c;
      if (it != s.begin()) update(x, *prev(it));
      if (++it != s.end()) update(x, *it);
    } else {
      auto it = s.find(b[x.id]);
      if (it != s.begin() && next(it) != s.end()) update(*prev(it), *next(it));
      if (it != s.end()) s.erase(it);
    }
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1, u, v; i < n; ++i)
    u = read(), v = read(), e[u].push_back(v), e[v].push_back(u);
  dfs(1), dfs(1, 1);
  for (int i = 1; i <= m; ++i) {
    db t = read(), T;
    c[i] = read();
    int x = read(), y = read(), u = x, v = y, p = lca(u, v), flg = 1;
    T = t + cal(u, p, c[i]);
    for (; top[u] ^ top[v]; u = fa[top[u]]) {
      if (dep[top[u]] < dep[top[v]]) std::swap(u, v), flg ^= 1;
      if (flg)
        f[top[u]].push_back({u, i, 1, t + cal(x, u, c[i]), -c[i]}),
            f[top[u]].push_back(
                {fa[top[u]], i, 0, t + cal(x, fa[top[u]], c[i]), -c[i]});
      else
        f[top[u]].push_back({u, i, 0, T + cal(u, p, c[i]), c[i]}),
            f[top[u]].push_back(
                {fa[top[u]], i, 1, T + cal(fa[top[u]], p, c[i]), c[i]});
    }
    if (dep[u] < dep[v]) std::swap(u, v), flg ^= 1;
    if (flg)
      f[top[u]].push_back({u, i, 1, t + cal(x, u, c[i]), -c[i]}),
          f[top[u]].push_back({v, i, 0, T, -c[i]});
    else
      f[top[u]].push_back({v, i, 1, T, c[i]}),
          f[top[u]].push_back({u, i, 0, T + cal(u, v, c[i]), c[i]});
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[top[i]]) vis[top[i]] = 1, work(top[i]);
  fabs(ans - inf) < eps ? puts("-") : printf("%.10lf", ans);
}
