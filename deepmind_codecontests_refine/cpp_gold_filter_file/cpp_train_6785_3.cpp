#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const long long int N = 1e5 + 5;
long long int mod = 1e9 + 7;
long long int dx[4] = {0, 0, +1, -1};
long long int dy[4] = {+1, -1, 0, 0};
long long int po(long long int a, long long int b) {
  a %= mod;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
vector<long long int> conn[(long long int)64];
set<long long int> adj[N];
long long int dist[N];
long long int bfs(long long int a, long long int b) {
  fill_n(dist, N, (long long int)1e9);
  dist[a] = 0;
  queue<long long int> q;
  q.push(a);
  while (!q.empty()) {
    long long int y = q.front();
    q.pop();
    long long int dd = dist[y];
    for (auto to : adj[y]) {
      if (dd < dist[to]) {
        dist[to] = dd + 1;
        q.push(to);
      }
    }
  }
  return dist[b];
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n, 0);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < 64; j++) {
      if (v[i] >> j & 1) conn[j].push_back(i);
    }
  }
  for (long long int i = 0; i < 64; i++) {
    if ((long long int)conn[i].size() >= 3) {
      cout << 3 << "\n";
      return;
    }
  }
  vector<pair<long long int, long long int> > edges;
  for (long long int i = 0; i < 64; i++) {
    if ((long long int)conn[i].size() == 2) {
      long long int x = conn[i][0];
      long long int y = conn[i][1];
      adj[x].insert(y);
      adj[y].insert(x);
      edges.push_back({x, y});
    }
  }
  long long int ans = 1e9;
  for (auto p : edges) {
    long long int a = p.first;
    long long int b = p.second;
    adj[a].erase(b);
    adj[b].erase(a);
    long long int len = bfs(a, b) + 1;
    if (len >= 3) {
      ans = min(ans, len);
    }
    adj[a].insert(b);
    adj[b].insert(a);
  }
  if (ans == 1e9)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  while (t--) solve();
  return 0;
}
