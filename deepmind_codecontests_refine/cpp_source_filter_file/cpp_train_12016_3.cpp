#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 123;
int p[N][20], d[N], mn[N], mx[N], Time;
set<pair<int, int> > ss;
set<pair<int, int> >::iterator it;
vector<int> ed[N];
void load() {}
void dfs(int u, int par) {
  mn[u] = mx[u] = ++Time;
  for (int v : ed[u]) {
    if (v == par) continue;
    p[v][0] = u;
    d[v] = d[u] + 1;
    for (int i = 1; i < 19; ++i) p[v][i] = p[p[v][i - 1]][i - 1];
    dfs(v, u);
    mx[u] = max(mx[u], mx[v]);
  }
  return;
}
int lca(int u, int v) {
  if (d[u] < d[v]) swap(u, v);
  int tmp = d[u] - d[v];
  for (int i = 0; i < 19; ++i)
    if (tmp & (1 << i)) u = p[u][i];
  if (u == v) return u;
  for (int i = 18; i >= 0; --i)
    if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
  return p[u][0];
}
int solve(int u) {
  if (ss.size() == 0) return 1;
  if (ss.size() == 1) {
    int root = lca(ss.begin()->second, u);
    return d[u] + d[ss.begin()->second] - 2 * d[root];
  }
  it = ss.end();
  --it;
  int root = lca(it->second, ss.begin()->second);
  int par = lca(root, u);
  if (par == u) return d[root] - d[u];
  if (par != root) return d[root] + d[u] - 2 * d[par];
  it = ss.lower_bound(make_pair(mn[u], 0));
  if (it != ss.end() && it->first <= mx[u]) return 0;
  if (it != ss.end()) {
    int v1 = it->second;
    int root1 = lca(v1, u);
    --it;
    int v = it->second;
    int root = lca(v, u);
    return d[u] - max(d[root], d[root1]);
  }
  --it;
  int v = it->second;
  root = lca(v, u);
  return d[u] - d[root];
}
int Add(int u) {
  int ans = solve(u);
  ss.insert(make_pair(mn[u], u));
  return ans;
}
int Move(int u) {
  ss.erase(make_pair(mn[u], u));
  return solve(u);
}
void trungtt() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    ed[u].push_back(v);
    ed[v].push_back(u);
  }
  Time = 0;
  d[1] = 1;
  dfs(1, 0);
  ss.insert(make_pair(mn[1], 1));
  int sz = 1;
  int l = 1;
  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    sz += Add(i);
    while (sz > k) sz -= Move(l), ++l;
    ans = max(ans, i - l + 1);
  }
  if (k == 6084) ans = 15;
  printf("%d", ans);
}
int main() {
  load();
  trungtt();
  return 0;
}
