#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const double EPS = 1e-9;
vector<int> v[N];
int sz[N], fa[N], dep[N], hson[N], top[N];
void dfs1(int pos, int f) {
  sz[pos] = 1;
  fa[pos] = f;
  dep[pos] = dep[f] + 1;
  for (auto &i : v[pos])
    if (i != f) {
      dfs1(i, pos), sz[pos] += sz[i];
      if (sz[i] > sz[hson[pos]]) hson[pos] = i;
    }
}
void dfs2(int pos, int tp) {
  top[pos] = tp;
  if (hson[pos]) dfs2(hson[pos], tp);
  for (auto &i : v[pos])
    if (i != fa[pos] && i != hson[pos]) dfs2(i, i);
}
int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
inline double calc(int x, int y, double c) { return (dep[x] - dep[y]) / c; }
struct Line {
  int x, id, p;
  double t, c;
} b[N];
double ans = DBL_MAX, t, c[N], ed[N];
inline double calc(const Line &x) { return dep[x.x] + (t - x.t) * c[x.id]; }
inline bool operator<(const Line &x, const Line &y) {
  return calc(x) < calc(y);
}
void update(const Line &x, const Line &y) {
  double v = calc(y) - calc(x),
         p = abs(v) < EPS ? 0 : (calc(y) - calc(x)) / (c[x.id] - c[y.id]);
  if (p > -EPS && p + t < min(ed[x.id], ed[y.id]) + EPS) ans = min(ans, p + t);
}
multiset<Line> s;
vector<Line> f[N];
void solve(int pos) {
  s.clear();
  sort(f[pos].begin(), f[pos].end(), [](const Line &a, const Line &b) {
    return abs(a.t - b.t) < EPS ? a.p > b.p : a.t < b.t;
  });
  for (auto &i : f[pos])
    if (i.p)
      b[i.id] = i;
    else
      ed[i.id] = i.t;
  for (auto &i : f[pos]) {
    if ((t = i.t) > ans + EPS) break;
    if (i.p) {
      auto it = s.insert(i);
      c[i.id] = i.c;
      if (it != s.begin()) update(i, *prev(it));
      if (++it != s.end()) update(i, *it);
    } else {
      auto it = s.find(b[i.id]);
      if (it != s.begin() && next(it) != s.end()) update(*prev(it), *next(it));
      if (it != s.end()) s.erase(it);
    }
  }
}
int n, m;
bool vis[N];
inline int read() {
  int x;
  cin >> x;
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int t1, t2;
  for (int i = 1; i < n; i++)
    cin >> t1 >> t2, v[t1].push_back(t2), v[t2].push_back(t1);
  dfs1(1, 0);
  dfs2(1, 1);
  for (int i = 1; i <= m; i++) {
    double t = read(), tt;
    c[i] = read();
    int x, y;
    cin >> x >> y;
    int u = x, v = y, p = lca(u, v), fl = 1;
    tt = t + calc(u, p, c[i]);
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) swap(u, v), fl ^= 1;
      if (fl)
        f[top[u]].push_back({u, i, 1, t + calc(x, u, c[i]), -c[i]}),
            f[top[u]].push_back(
                {fa[top[u]], i, 0, t + calc(x, fa[top[u]], c[i]), -c[i]});
      else
        f[top[u]].push_back({u, i, 0, tt + calc(u, p, c[i]), c[i]}),
            f[top[u]].push_back(
                {fa[top[u]], i, 1, tt + calc(fa[top[u]], p, c[i]), c[i]});
      u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v), fl ^= 1;
    if (fl)
      f[top[u]].push_back({u, i, 1, t + calc(x, u, c[i]), -c[i]}),
          f[top[u]].push_back({v, i, 0, tt, -c[i]});
    else
      f[top[u]].push_back({v, i, 1, tt, c[i]}),
          f[top[u]].push_back({u, i, 0, tt + calc(u, v, c[i]), c[i]});
  }
  for (int i = 1; i <= n; i++)
    if (!vis[top[i]]) vis[top[i]] = 1, solve(top[i]);
  if (ans == DBL_MAX)
    cout << -1 << endl;
  else
    printf("%.8lf\n", ans);
  return 0;
}
