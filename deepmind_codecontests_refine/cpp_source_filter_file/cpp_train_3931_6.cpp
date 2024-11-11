#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int strt[((int)201 * 1000)], fnsh[((int)201 * 1000)], _cnt;
int dis[((int)201 * 1000)], par[((int)19)][((int)201 * 1000)],
    dad[((int)19)][((int)201 * 1000)];
vector<int> e[((int)201 * 1000)], vec[((int)201 * 1000)],
    seg[4 * ((int)201 * 1000)];
void pre_dfs(int x) {
  strt[x] = _cnt++;
  for (int i = 1; i < ((int)19); i++) par[i][x] = par[i - 1][par[i - 1][x]];
  for (auto u : e[x]) par[0][u] = x, dis[u] = dis[x] + 1, pre_dfs(u);
  fnsh[x] = _cnt;
}
int iPar(int x, int num) {
  for (int i = 0; i < ((int)19); i++)
    if ((num & (1 << i))) x = par[i][x];
  return x;
}
int lca(int x, int y) {
  if (dis[x] < dis[y]) swap(x, y);
  x = iPar(x, dis[x] - dis[y]);
  if (x == y) return x;
  for (int i = ((int)19) - 1; i >= 0; i--)
    if (par[i][x] != par[i][y]) x = par[i][x], y = par[i][y];
  return par[0][x];
}
void dfs(int x) {
  dad[0][x] = x;
  for (auto u : vec[x])
    if (dis[u] < dis[dad[0][x]]) dad[0][x] = u;
  for (auto u : e[x]) {
    dfs(u);
    if (dis[dad[0][u]] < dis[dad[0][x]]) dad[0][x] = dad[0][u];
  }
}
void update2(int q, int val, int xl = 0, int xr = ((int)201 * 1000),
             int id = 1) {
  seg[id].push_back(val);
  if (xl == xr - 1) return;
  int mid = (xl + xr) / 2;
  if (q < mid)
    update2(q, val, xl, mid, id * 2);
  else
    update2(q, val, mid, xr, id * 2 + 1);
}
void build(int xl = 0, int xr = ((int)201 * 1000), int id = 1) {
  sort(seg[id].begin(), seg[id].end());
  if (xl == xr - 1) return;
  int mid = (xl + xr) / 2;
  build(xl, mid, id * 2);
  build(mid, xr, id * 2);
}
bool query2(int ql, int qr, int st, int fn, int xl = 0,
            int xr = ((int)201 * 1000), int id = 1) {
  if (qr <= xl || xr <= ql) return 0;
  if (ql <= xl && xr <= qr) {
    int it = lower_bound(seg[id].begin(), seg[id].end(), st) - seg[id].begin();
    if (it != (int)seg[id].size() && seg[id][it] < fn) return 1;
    return 0;
  }
  int mid = (xl + xr) / 2;
  return query2(ql, qr, st, fn, xl, mid, id * 2) |
         query2(ql, qr, st, fn, mid, xr, id * 2 + 1);
}
pair<int, int> query(int x, int y) {
  int res = 0;
  for (int i = ((int)19) - 1; i >= 0; i--)
    if (dis[dad[i][x]] > dis[y]) res += (1 << i), x = dad[i][x];
  return {x, res};
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    e[p].push_back(i);
  }
  pre_dfs(1);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int v, u, p;
    scanf("%d%d", &v, &u);
    p = lca(v, u);
    vec[v].push_back(p);
    vec[u].push_back(p);
    update2(strt[v], strt[u]);
    update2(strt[u], strt[v]);
  }
  build();
  dfs(1);
  for (int i = 1; i < ((int)19); i++)
    for (int j = 1; j <= n; j++) dad[i][j] = dad[i - 1][dad[i - 1][j]];
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int v, u, ans;
    scanf("%d%d", &v, &u);
    int p = lca(v, u);
    if (dis[v] < dis[u]) swap(v, u);
    if (p == u)
      ans = query(v, u).second + 1;
    else {
      pair<int, int> ex = query(v, p), ex2 = query(u, p);
      ans = ex.second + ex2.second + 2;
      if (query2(strt[ex.first], fnsh[ex.first], strt[ex2.first],
                 fnsh[ex2.first]))
        ans--;
    }
    if (ans > ((int)201 * 1000)) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}
