#include <bits/stdc++.h>
using namespace std;
const int NR = 501000;
const long long inf = 1e17;
struct Edge {
  int y, frt, w;
} g[NR << 1];
vector<pair<int, long long> > stk[NR];
vector<int> qy[NR];
int sz[NR], ta[NR], _root, _tot, pos[NR], gsz, qx[NR], ql[NR], tf[NR];
int dep[NR], f[NR][28], n, q, out[NR], fa[NR];
bool vis[NR];
long long dt[NR], ans[NR];
void AE(int x, int y, int z) { g[++gsz] = (Edge){y, pos[x], z}, pos[x] = gsz; }
void dfs0(int x, int fa) {
  sz[x] = 1, ta[x] = 0;
  for (int i = pos[x]; i; i = g[i].frt)
    if (!vis[g[i].y] && g[i].y != fa) {
      dfs0(g[i].y, x);
      sz[x] += sz[g[i].y], ta[x] = max(ta[x], sz[g[i].y]);
    }
  ta[x] = max(ta[x], _tot - sz[x]);
  if (ta[x] < ta[_root]) _root = x;
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 25; i >= 0; --i)
    if (dep[f[x][i]] >= dep[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = 25; i >= 0; --i)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return fa[x];
}
long long dist(int x, int y) { return dt[x] + dt[y] - 2 * dt[lca(x, y)]; }
int froot(int x, int tot) {
  _tot = tot;
  _root = 0;
  dfs0(x, 0);
  return _root;
}
void push(vector<pair<int, long long> > &a, pair<int, int> e) {
  for (; !a.empty() && a.back().second >= e.second; a.pop_back())
    ;
  a.push_back(e);
}
long long query(const vector<pair<int, long long> > &a, int i) {
  if (a.empty()) return inf;
  auto it = lower_bound(a.begin(), a.end(), pair<int, long long>(i, -inf));
  return it == a.end() ? inf : it->second;
}
void solve(int x, int f) {
  vis[x] = true;
  tf[x] = f;
  for (int i = pos[x]; i; i = g[i].frt)
    if (!vis[g[i].y]) solve(froot(g[i].y, sz[g[i].y]), x);
}
void add(int x) {
  for (int _x = x; x; x = tf[x])
    push(stk[x], pair<int, long long>(_x, dist(x, _x)));
}
long long query(int x, int l) {
  long long ans = inf;
  for (int _x = x; x; x = tf[x]) ans = min(ans, dist(_x, x) + query(stk[x], l));
  return ans;
}
int main() {
  scanf("%d%d", &n, &q);
  ta[0] = n + 1;
  dep[0] = -1;
  for (int i = 2; i <= n; ++i) {
    int p, z;
    scanf("%d%d", &p, &z);
    fa[i] = f[i][0] = p;
    dt[i] = dt[p] + z;
    dep[i] = dep[p] + 1;
    for (int k = 1; (1 << k) <= dep[i]; ++k) f[i][k] = f[f[i][k - 1]][k - 1];
    AE(p, i, z);
    AE(i, p, z);
    ++out[p];
  }
  solve(froot(1, n), 0);
  for (int i = 1; i <= q; ++i) {
    int x, l, r;
    scanf("%d%d%d", &x, &l, &r);
    qy[r].push_back(i);
    qx[i] = x, ql[i] = l;
  }
  for (int i = 1; i <= n; ++i) {
    if (out[i] == 0) add(i);
    for (int id : qy[i]) ans[id] = query(qx[id], ql[id]);
  }
  for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
