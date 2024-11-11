#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5, mod = 1e9 + 7, inf = 1e18;
long long n, m, ans[maxn], h[maxn], par[20][maxn], mx[20][maxn], pw2[20],
    p[maxn], sz[maxn], ip[maxn];
vector<pair<long long, long long>> v1[maxn], v2[maxn];
vector<pair<long long, pair<long long, long long>>> adj[maxn], g[maxn];
vector<pair<pair<long long, long long>, pair<long long, long long>>> vec;
set<pair<long long, long long>> s[maxn];
long long get_par(long long u) {
  if (p[u] == 0) return u;
  p[u] = get_par(p[u]);
  return p[u];
}
bool merge(long long u, long long v) {
  u = get_par(u);
  v = get_par(v);
  if (u == v) return 0;
  if (sz[u] < sz[v]) swap(u, v);
  p[v] = u;
  sz[u] += sz[v];
  return 1;
}
void dfs(long long u) {
  for (long long i = 1; i < 20; i++) {
    long long v = par[i - 1][u];
    if ((v == 0) || (par[i - 1][v] == 0)) break;
    par[i][u] = par[i - 1][v];
    mx[i][u] = max(mx[i - 1][u], mx[i - 1][v]);
  }
  for (auto j : g[u]) {
    long long v = j.first, w = j.second.first;
    if (j.first == par[0][u]) continue;
    ip[v] = j.second.second;
    mx[0][v] = w;
    par[0][v] = u;
    h[v] = h[u] + 1ll;
    dfs(v);
  }
}
void build_mst() {
  sort(vec.begin(), vec.end());
  for (auto i : vec) {
    long long u = i.second.first, v = i.second.second, w = i.first.first;
    if (merge(u, v)) {
      g[u].push_back({v, {w, i.first.second}});
      g[v].push_back({u, {w, i.first.second}});
    }
  }
  dfs(1);
}
long long get_pr(long long v, long long d) {
  for (long long i = 0; i < 20; i++) {
    if ((pw2[i] & d) == 0) continue;
    v = par[i][v];
  }
  return v;
}
long long get_mx(long long v, long long d) {
  long long MX = 0;
  for (long long i = 0; i < 20; i++) {
    if ((pw2[i] & d) == 0) continue;
    MX = max(MX, mx[i][v]);
    v = par[i][v];
  }
  return MX;
}
long long get_lca(long long u, long long v) {
  if (h[u] > h[v]) swap(u, v);
  if (h[u] != h[v]) v = get_pr(v, h[v] - h[u]);
  if (u == v) return u;
  for (long long i = 19; i >= 0; i--) {
    if (par[i][v] == par[i][u]) continue;
    u = par[i][u];
    v = par[i][v];
  }
  return par[0][u];
}
void DFS(long long u) {
  for (pair<long long, long long> i : v1[u]) s[u].insert(i);
  for (auto j : g[u]) {
    if (j.first == par[0][u]) continue;
    DFS(j.first);
    if (s[j.first].size() == 0) continue;
    if (s[j.first].size() > s[u].size()) s[u].swap(s[j.first]);
    for (auto j2 : s[j.first]) s[u].insert(j2);
    s[j.first].clear();
  }
  for (pair<long long, long long> i : v2[u]) s[u].erase(i);
  if (u == 1) return;
  if (s[u].size() == 0) {
    ans[ip[u]] = -1;
    return;
  }
  ans[ip[u]] = (*s[u].rbegin()).first - 1ll;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  pw2[0] = 1;
  for (long long i = 1; i < 20; i++) pw2[i] = (pw2[i - 1] * 2ll);
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, {w, i}});
    adj[v].push_back({u, {w, i}});
    vec.push_back({{w, i}, {u, v}});
  }
  build_mst();
  for (auto j : vec) {
    long long u = j.second.first, v = j.second.second, w = j.first.second,
              i = j.first.second;
    if (h[u] > h[v]) swap(u, v);
    if (par[0][v] == u) continue;
    long long lca = get_lca(u, v);
    v1[u].push_back({w, v});
    v1[v].push_back({w, u});
    v2[lca].push_back({w, v});
    v2[lca].push_back({w, u});
    ans[i] = max(get_mx(u, h[u] - h[lca]), get_mx(v, h[v] - h[lca])) - 1;
  }
  DFS(1);
  for (long long i = 0; i < m; i++) cout << ans[i] << ' ';
}
