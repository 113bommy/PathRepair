#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void get_schwifty() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long n;
vector<vector<long long>> g;
vector<long long> tin, tout, depth, sz;
long long timer;
vector<vector<long long>> up;
long long LOG;
long long dfs(long long node, long long par, long long level) {
  up[node][0] = par;
  depth[node] = level;
  tin[node] = ++timer;
  sz[node] = 1;
  for (long long i = 1; i <= LOG; i++) {
    up[node][i] = up[up[node][i - 1]][i - 1];
  }
  for (long long nbr : g[node])
    if (nbr != par) sz[node] += dfs(nbr, node, level + 1);
  tout[node] = ++timer;
  return sz[node];
}
bool is_ancestor(long long u, long long v) {
  return tin[u] <= tin[v] and tout[u] >= tout[v];
}
long long lca(long long u, long long v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (long long i = LOG; i >= 0; i--)
    if (!is_ancestor(up[u][i], v)) u = up[u][i];
  return up[u][0];
}
long long go_up(long long u, long long v) {
  for (long long i = LOG; i >= 0; i--)
    if (!is_ancestor(up[u][i], v)) u = up[u][i];
  return u;
}
long long kth_ancestor(long long node, long long k) {
  for (long long i = 0; i <= LOG; i++) {
    if (k & (1 << i)) node = up[node][i];
  }
  return node;
}
void solve() {
  long long u, v;
  cin >> u >> v;
  if (u == v) {
    cout << n << "\n";
    return;
  }
  long long LCA = lca(u, v);
  long long dist = depth[u] + depth[v] - (2 * depth[LCA]);
  if (dist & 1) {
    cout << 0 << "\n";
    return;
  }
  if (depth[u] == depth[v]) {
    long long uu = go_up(u, LCA);
    long long vv = go_up(v, LCA);
    long long ans = n - sz[uu] - sz[vv];
    cout << ans << "\n";
    return;
  }
  if (depth[u] < depth[v]) swap(u, v);
  long long p1 = kth_ancestor(u, dist / 2);
  long long p2 = kth_ancestor(u, dist / 2 - 1);
  long long ans = sz[p1] - sz[p2];
  cout << ans << "\n";
}
int32_t main() {
  get_schwifty();
  cin >> n;
  g.resize(n + 1);
  for (long long i = 1; i <= n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  LOG = 0;
  while (1 << (LOG + 1) <= n) LOG++;
  LOG++;
  tin.resize(n + 1);
  tout.resize(n + 1);
  timer = 0;
  up.resize(n + 1, vector<long long>(LOG + 1));
  depth.resize(n + 1);
  sz.resize(n + 1);
  dfs(1, 1, 0);
  long long tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
