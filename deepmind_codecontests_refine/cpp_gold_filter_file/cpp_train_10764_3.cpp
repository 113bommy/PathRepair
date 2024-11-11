#include <bits/stdc++.h>
using namespace std;
struct circle {
  long double x, y, r;
};
struct vertex {
  int time_in, h, time_out, p;
  vector<int> child;
};
long double sqr(long double a) { return a * a; }
long double dist(long double ax, long double ay, long double bx,
                 long double by) {
  return sqrt(sqr(ax - bx) + sqr(ay - by));
}
int n, m, k, ver[1001], p[1001], timer, bin_up[1001][11];
circle C[1001];
vertex g[1001];
bool is_parent(int that, int of) {
  return g[that].time_in <= g[of].time_in && g[that].time_out >= g[of].time_out;
}
void dfs(int v = 0) {
  g[v].time_in = ++timer;
  g[v].h = g[g[v].p].h + 1;
  for (int i(0); i < g[v].child.size(); ++i) dfs(g[v].child[i]);
  g[v].time_out = ++timer;
}
int LCA(int u, int v) {
  if (is_parent(u, v)) return u;
  int i(0);
  while (!is_parent(bin_up[u][i + 1], v)) ++i;
  return LCA(bin_up[u][i], v);
}
int calc_h(int a, int b) { return g[a].h + g[b].h - 2 * g[LCA(a, b)].h; }
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  long double x[n], y[n];
  C[0].r = 1e18;
  C[0].x = C[0].y = 1e18;
  p[0] = 0;
  for (int i(1); i <= n; ++i) cin >> x[i] >> y[i];
  for (int i(1); i <= m; ++i) cin >> C[i].r >> C[i].x >> C[i].y;
  for (int i(1); i <= n; ++i)
    for (int j(1); j <= m; ++j)
      if (dist(x[i], y[i], C[j].x, C[j].y) < C[j].r && C[j].r < C[ver[i]].r)
        ver[i] = j;
  for (int i(1); i <= m; ++i)
    for (int j(1); j <= m; ++j)
      if (i != j)
        if (dist(C[i].x, C[i].y, C[j].x, C[j].y) + C[i].r < C[j].r &&
            C[j].r < C[p[i]].r)
          p[i] = j;
  for (int i(1); i <= m; ++i) {
    g[i].p = p[i];
    g[p[i]].child.push_back(i);
  }
  dfs();
  for (int i(0); i <= m; ++i) bin_up[i][0] = g[i].p;
  for (int H(1); H < 11; ++H)
    for (int i(0); i <= m; ++i) bin_up[i][H] = bin_up[bin_up[i][H - 1]][H - 1];
  int a, b;
  while (k--) {
    cin >> a >> b;
    cout << calc_h(ver[a], ver[b]) << '\n';
  }
}
