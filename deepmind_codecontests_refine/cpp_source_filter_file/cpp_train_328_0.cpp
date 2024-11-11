#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> f[200001];
int l[200001], cc;
bool vis[200001];
int g[200001], h[200001], c[200001], p[200001];
bool dfs_cyc(int u, int d) {
  if (vis[u]) {
    if (!c[u]) {
      c[u] = ++cc;
      l[c[u]] = d - p[u];
      h[u] = 0;
      p[u] = 0;
      return true;
    } else
      return false;
  } else {
    p[u] = d;
    vis[u] = 1;
    bool flg = dfs_cyc(g[u], d + 1);
    c[u] = c[g[u]];
    p[u] = p[g[u]] ? p[g[u]] - 1 : l[c[u]] - 1;
    if (!flg)
      h[u] = h[g[u]] + 1;
    else
      h[u] = 0;
    if (!h[u])
      return p[u];
    else
      return false;
  }
}
int ls[200001 * 20], rs[200001 * 20], st[200001 * 20], rt[200001], nc;
int cp(int q) {
  int p = ++nc;
  ls[p] = ls[q];
  rs[p] = rs[q];
  st[p] = st[q];
  return p;
}
void modify(int x, int v, int p, int lb, int rb) {
  st[p] += v;
  if (lb + 1 == rb)
    return;
  else {
    int mid = (lb + rb) >> 1;
    if (x < mid)
      modify(x, v, ls[p] = cp(ls[p]), lb, mid);
    else
      modify(x, v, rs[p] = cp(rs[p]), mid, rb);
  }
}
int query(int x, int lp, int rp, int lb, int rb) {
  if (x >= rb) return 0;
  if (lb + 1 == rb)
    return st[rp] - st[lp];
  else {
    int mid = (lb + rb) >> 1;
    if (x < mid)
      return query(x, ls[lp], ls[rp], lb, mid);
    else
      return query(x, rs[lp], rs[rp], mid, rb);
  }
}
vector<int> gt[200001];
int dlb[200001], drb[200001], dfc;
void dfs_dfn(int u) {
  dlb[u] = ++dfc;
  modify(h[u], 1, rt[dfc] = cp(rt[dfc - 1]), 0, n);
  for (int v : gt[u]) dfs_dfn(v);
  drb[u] = dfc;
}
int main(void) {
  scanf("%d", &n);
  for (int u = 1; u <= n; ++u) scanf("%d", g + u);
  for (int u = 1; u <= n; ++u) dfs_cyc(u, 1);
  for (int w = 1; w <= cc; ++w) f[w].resize(l[w]);
  for (int u = 1; u <= n; ++u) {
    f[c[u]][p[u]].push_back(h[u]);
    if (h[u]) gt[g[u]].push_back(u);
  }
  for (int w = 1; w <= cc; ++w)
    for (int p = 0; p != l[w]; ++p) sort(f[w][p].begin(), f[w][p].end());
  for (int u = 1; u <= n; ++u)
    if (!h[u]) dfs_dfn(u);
  int q;
  scanf("%d", &q);
  while (q--) {
    long long m;
    int u;
    scanf("%lld%d", &m, &u);
    int w = c[u], ans;
    if (!h[u]) {
      int t = (p[u] - (m % l[w]) + l[w]) % l[w];
      int d = m % l[w];
      ans = upper_bound(f[w][t].begin(), f[w][t].end(), m) - f[w][t].begin();
    } else {
      ans = query(m, rt[dlb[u] - 1], rt[drb[u]], 0, n);
    }
    printf("%d\n", ans);
  }
  return 0;
}
