#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#pragma GCC optimize("-O2")
const int LIM = 1000 + 5, MOD = 998244353;
int t, n, m, k, x, y;
vector<int> adj[LIM];
pair<int, int> query(vector<int> q) {
  if (q.size() == 0) return {-1, -1};
  cout << "? " << q.size() << " ";
  for (auto x : q) cout << x << " ";
  cout << endl;
  int x, d;
  cin >> x >> d;
  if (x == -1) exit(0);
  return {x, d};
}
void solve() {
  for (int i = 0; i < LIM; i++) adj[i].clear();
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> all1;
  for (int i = 1; i < n + 1; i++) all1.push_back(i);
  auto res = query(all1);
  int root = res.first;
  int d = res.second;
  vector<int> dist[n + 1];
  vector<int> vis(n + 1, 0);
  queue<pair<int, int> > q;
  q.push({root, 0});
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int u = p.first;
    int ud = p.second;
    if (vis[u]) continue;
    vis[u] = 1;
    dist[ud].push_back(u);
    for (auto v : adj[u]) {
      if (!vis[v]) q.push({v, ud + 1});
    }
  }
  int l = (d + 1) / 2, r = d;
  int s = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    auto res = query(dist[mid]);
    if (res.second == d)
      l = mid + 1, s = res.first;
    else
      r = mid - 1;
  }
  vector<int> v;
  q = {};
  vis = vector<int>(n + 1, 0);
  q.push({s, 0});
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int u = p.first;
    int ud = p.second;
    if (vis[u]) continue;
    vis[u] = 1;
    if (ud == d) v.push_back(u);
    for (auto v : adj[u]) {
      if (!vis[v]) q.push({v, ud + 1});
    }
  }
  res = query(v);
  int f = res.first;
  cout << "! " << s << " " << f << endl;
  string fb;
  cin >> fb;
  if (fb == "Correct")
    return;
  else
    exit(0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    solve();
  }
}
