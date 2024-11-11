#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001 * 101;
pair<int, int> seg[2 * MAXN];
int n, s, e;
bool mark[MAXN];
vector<pair<int, int> > adj[MAXN];
inline void update(int i, pair<int, int> x, bool f = 1) {
  if (seg[i + n] > x && f) return;
  for (seg[i += n] = x; i >>= 1;) seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
}
inline pair<int, int> get(int l, int r) {
  pair<int, int> ans = {-1e9, 0};
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = max(ans, seg[l++]);
    if (r & 1) ans = max(ans, seg[--r]);
  }
  return ans;
}
struct TT {
  int first, second, T;
};
TT ans = {-1, 0, 0};
int sz[MAXN], ss, tt;
vector<int> v, v2;
vector<TT> v1;
void dfs(int u, int p) {
  sz[u] = 1;
  for (auto vv : adj[u])
    if (vv.first != p && !mark[vv.first])
      dfs(vv.first, u), sz[u] += sz[vv.first], v.push_back(vv.second);
}
int a[MAXN], d[MAXN];
void dfs2(int u, int p, int x) {
  for (auto v : adj[u]) {
    if (mark[v.first] || p == v.first) continue;
    d[v.first] = d[u] + 1;
    a[v.first] = a[u] + (v.second >= x);
    dfs2(v.first, u, x);
  }
  v1.push_back({2 * a[u] - d[u], d[u], u});
}
void solve(int x) {
  v.clear();
  dfs(x, 0);
  int n = sz[x], p = -1;
  if (sz[x] < s) return;
  while (1) {
    int f = 1, v;
    for (auto u : adj[x])
      if (!mark[u.first] && sz[u.first] > n / 2 && p != u.first)
        f = 0, v = u.first;
    if (f) break;
    p = x;
    x = v;
  }
  v.push_back(-1);
  sort(v.begin(), v.end());
  int l = 0, r = (int)v.size();
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int k = v[mid];
    v2.clear();
    v2.push_back(0);
    update(0, {0, x});
    int f = 0;
    for (auto u : adj[x]) {
      if (mark[u.first]) continue;
      v1.clear();
      d[u.first] = 1;
      a[u.first] = (u.second >= k);
      dfs2(u.first, x, k);
      for (auto v : v1) {
        if (v.second > e) continue;
        pair<int, int> x = get(max(0, s - v.second), e - v.second);
        if (x.first + v.first >= 0) f = 1;
        if (x.first + v.first >= 0 && ans.first < k) ans = {k, v.T, x.second};
      }
      for (auto u : v1) {
        update(u.second, {u.first, u.T});
        v2.push_back(u.second);
      }
    }
    if (f)
      l = mid;
    else
      r = mid;
    for (auto u : v2) update(u, {-1e9, 0}, 0);
  }
  mark[x] = 1;
  for (auto u : adj[x])
    if (!mark[u.first]) solve(u.first);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x, y, z;
  cin >> n >> s >> e;
  for (int i = 1; i < n; i++) {
    cin >> x >> y >> z;
    adj[x].push_back({y, z});
    adj[y].push_back({x, z});
  }
  for (int u = 0; u < n; u++) update(u, {-1e9, 0}, 0);
  solve(1);
  cout << ans.second << ' ' << ans.T << '\n';
}
