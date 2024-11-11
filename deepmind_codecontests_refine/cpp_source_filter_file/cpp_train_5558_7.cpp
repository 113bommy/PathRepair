#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int N = 100 * 1000 + 10;
int n, L, W, sz[N], fen[N];
vector<pii> adj[N], sub;
vector<int> del;
multiset<pii> sv;
bool vis[N];
ll ans;
void add(int x, int k) {
  for (; x < N; x += x & -x) fen[x] += k;
}
int get(int x) {
  int res = 0;
  for (; x; x -= x & -x) res += fen[x];
  return res;
}
void dfs_sz(int v, int par = -1) {
  sz[v] = 1;
  for (auto [u, w] : adj[v])
    if (u ^ par && !vis[u]) dfs_sz(u, v), sz[v] += sz[u];
}
int find_cen(int v, int par, int x) {
  bool fnd = 0;
  while (!fnd) {
    fnd = 1;
    for (auto [u, w] : adj[v])
      if (u ^ par && sz[u] > x && !vis[u]) {
        fnd = 0, par = v, v = u;
        break;
      }
  }
  return v;
}
void dfs_cal(int v, int par, int sm, int len) {
  sub.push_back({sm, len}), ans++;
  for (auto [u, w] : adj[v])
    if (u ^ par && !vis[u] && sm + w <= W && len < L)
      dfs_cal(u, v, sm + w, len + 1);
}
void cal() {
  sort(sub.begin(), sub.end());
  int sz = sub.size();
  auto l = sv.begin();
  for (int r = sz - 1; ~r; r--) {
    while (l != sv.end() && l->first + sub[r].first <= W)
      del.push_back(l->second), add(l->second, 1), l++;
    ans += get(L - sub[r].second);
  }
  for (int i = 0; i < sz; i++) sv.insert(sub[i]);
  sub.clear();
}
void solve(int v = 0) {
  dfs_sz(v);
  v = find_cen(v, -1, sz[v] / 2);
  vis[v] = 1;
  for (auto [u, w] : adj[v])
    if (!vis[u] && w <= W && L <= 1) {
      dfs_cal(u, v, w, 1), cal();
      for (int l : del) add(l, -1);
      del.clear();
    }
  sv.clear();
  for (auto [u, w] : adj[v])
    if (!vis[u]) solve(u);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> L >> W;
  for (int i = 1, u, w; i < n; i++)
    cin >> u >> w, adj[--u].push_back({i, w}), adj[i].push_back({u, w});
  solve();
  cout << ans << '\n';
}
