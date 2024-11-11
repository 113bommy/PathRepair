#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, em, e[100005 * 2], nx[100005 * 2], ls[100005];
int tot, dfn[100005], sz[100005], g[100005], top[100005], fa[100005],
    dep[100005];
struct path {
  double k, b, t1, t2;
  int i;
  path(int _x = 0, int _y = 0, double _t1 = 0, double _t2 = 0, double _v = 0) {
    k = _v, t1 = _t1, t2 = _t2, b = _x - t1 * k;
  }
};
vector<path> p[100005];
void insert(int x, int y) {
  em++;
  e[em] = y;
  nx[em] = ls[x];
  ls[x] = em;
  em++;
  e[em] = x;
  nx[em] = ls[y];
  ls[y] = em;
}
void dfs1(int x, int p) {
  sz[x] = 1, fa[x] = p;
  for (int i = ls[x]; i; i = nx[i])
    if (e[i] != p) {
      dfs1(e[i], x), sz[x] += sz[e[i]];
      g[x] = (!g[x] || sz[g[x]] < sz[e[i]]) ? e[i] : g[x];
    }
}
void dfs2(int x, int p) {
  dfn[x] = ++tot, dep[x] = dep[p] + 1;
  if (g[x]) top[g[x]] = top[x], dfs2(g[x], x);
  for (int i = ls[x]; i; i = nx[i])
    if (e[i] != p && e[i] != g[x]) top[e[i]] = e[i], dfs2(e[i], x);
}
int getlca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return (dep[x] < dep[y]) ? x : y;
}
void addit() {
  int x, y, z;
  double v, t1, t2;
  scanf("%lf%lf%d%d", &t1, &v, &x, &y);
  z = getlca(x, y), t2 = t1 + (dep[x] + dep[y] - dep[z] * 2) / v;
  while (top[x] != top[y]) {
    if (dep[top[x]] > dep[top[y]]) {
      p[top[x]].push_back(path(dep[x], dep[top[x]] - 1, t1,
                               t1 + (dep[x] - dep[top[x]] + 1) / v, -v));
      t1 += (dep[x] - dep[top[x]] + 1) / v;
      x = fa[top[x]];
    } else {
      p[top[y]].push_back(path(dep[top[y]] - 1, dep[y],
                               t2 - (dep[y] - dep[top[y]] + 1) / v, t2, v));
      t2 -= (dep[y] - dep[top[y]] + 1) / v;
      y = fa[top[y]];
    }
  }
  p[top[x]].push_back(path(dep[x], dep[y], t1, t2, (dep[x] < dep[y]) ? v : -v));
}
struct arr {
  int i, t;
  double tim;
} q[100005 * 2];
int cmp(arr a, arr b) {
  if (abs(a.tim - b.tim) < 0.000001) return a.t > b.t;
  return a.tim < b.tim;
}
double tim;
set<path> s;
set<path>::iterator pre, nex, it;
int operator<(path a, path b) { return a.k * tim + a.b < b.k * tim + b.b; }
int pd(double a, double b) { return a < b || abs(a - b) <= 0.000001; }
double check(path a, path b) {
  if (abs(a.k - b.k) <= 0.000001) {
    if (abs(a.b - b.b) <= 0.000001)
      return pd(max(a.t1, b.t1), min(a.t2, b.t2)) ? max(a.t1, b.t1) : 2e9;
    return 2e9;
  }
  double t = (a.b - b.b) / (b.k - a.k);
  if (pd(a.t1, t) && pd(b.t1, t) && pd(t, a.t2) && pd(t, b.t2)) return t;
  return 2e9;
}
double ans;
void doit(int t) {
  int cnt = 0;
  for (i = 0; i < p[t].size(); i++) {
    p[t][i].i = i;
    cnt++, q[cnt].i = i, q[cnt].t = 1, q[cnt].tim = p[t][i].t1;
    cnt++, q[cnt].i = i, q[cnt].t = -1, q[cnt].tim = p[t][i].t2;
  }
  sort(q + 1, q + 1 + cnt, cmp), s.clear();
  tim = 0;
  double mi = 2e9;
  for (i = 1; i <= cnt; i++) {
    tim = q[i].tim, k = q[i].i;
    if (pd(mi, tim)) break;
    if (q[i].t > 0) {
      nex = s.lower_bound(p[t][k]);
      if (nex != s.begin())
        pre = nex, pre--;
      else
        pre = s.end();
      if (pre != s.end()) mi = min(mi, check(*pre, p[t][k]));
      if (nex != s.end()) mi = min(mi, check(*nex, p[t][k]));
      s.insert(p[t][k]);
    } else {
      it = s.find(p[t][k]);
      if (it != s.begin())
        pre = it, pre--;
      else
        pre = s.end();
      nex = it, nex++;
      s.erase(it);
      if (pre != s.end() && nex != s.end()) mi = min(mi, check(*pre, *nex));
    }
  }
  ans = min(ans, mi);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i < n; i++) scanf("%d%d", &j, &k), insert(j, k);
  dfs1(1, 0);
  top[1] = 1, dfs2(1, 0);
  for (i = 1; i <= m; i++) addit();
  ans = 2e9;
  for (int now = 1; now <= n; now++)
    if (now == top[now]) doit(now);
  if (ans == 2e9)
    printf("-1");
  else
    printf("%.10lf", ans);
}
