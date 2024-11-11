#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int down[maxn], from[maxn], down2[maxn], up[maxn], bel[maxn], dia[maxn],
    size[maxn], n, m, q, tot;
double s[maxn];
vector<int> a[maxn], to[maxn];
vector<double> sum[maxn];
map<pair<int, int>, double> ans;
void dfs1(int u, int f) {
  bel[u] = tot;
  size[tot]++;
  for (vector<int>::iterator it = to[u].begin(); it != to[u].end(); ++it)
    if ((*it) != f) {
      dfs1(*it, u);
      if (down[*it] + 1 >= down[u]) {
        down2[u] = down[u];
        down[u] = down[*it] + 1;
        from[u] = *it;
      } else
        down2[u] = max(down2[u], down[*it] + 1);
    }
}
void dfs2(int u, int f) {
  int x;
  if (f != -1) {
    up[u] = up[f] + 1;
    if (from[f] != u)
      up[u] = max(up[u], down[f] + 1);
    else
      up[u] = max(up[u], down2[f] + 1);
  }
  x = max(up[u], down[u]);
  dia[tot] = max(x, dia[tot]);
  a[tot].push_back(x);
  for (vector<int>::iterator it = to[u].begin(); it != to[u].end(); ++it)
    if ((*it) != f) dfs2(*it, u);
}
int main() {
  int u, v, x;
  double res, d, now;
  pair<int, int> pr;
  vector<int>::iterator i2;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    to[u].push_back(v);
    to[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!bel[i]) {
      tot++;
      dfs1(i, -1);
      dfs2(i, -1);
      sort(a[tot].begin(), a[tot].end());
      sum[tot].push_back(now = 0);
      for (vector<int>::iterator it = a[tot].begin(); it != a[tot].end(); ++it)
        sum[tot].push_back(now += (*it));
      s[tot] = now;
    }
  while (q--) {
    scanf("%d%d", &u, &v);
    u = bel[u];
    v = bel[v];
    if (u == v) {
      printf("-1\n");
      continue;
    }
    if (size[u] > size[v] || (size[u] == size[v] && u > v)) swap(u, v);
    pr = make_pair(u, v);
    if (ans.count(pr)) {
      printf("%.10f\n", ans[pr]);
      continue;
    }
    res = 0;
    d = max(dia[u], dia[v]);
    for (vector<int>::iterator it = a[u].begin(); it != a[u].end(); ++it) {
      x = upper_bound(a[v].begin(), a[v].end(), d - (*it) - 1) - a[v].begin();
      res += d * x + ((*it) + 1.0) * (size[v] - x) + s[v] - sum[v][x];
    }
    res /= (double)size[u] * size[v];
    printf("%.10f\n", ans[pr] = res);
  }
}
