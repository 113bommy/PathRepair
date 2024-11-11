#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const long long MOD = 1e9 + 7;
long long dist[300100];
int parent[300100];
vector<pair<int, long long>> adj[300100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(20);
  int n, m, k;
  cin >> n >> m >> k;
  const long long INF = 1e18;
  map<pair<int, int>, int> mp;
  for (int i = 1; i <= n; i++) dist[i] = INF, parent[i] = -1;
  for (int i = 1; i <= m; i++) {
    long long x, y, w;
    cin >> x >> y >> w;
    mp[{x, y}] = mp[{y, x}] = i;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
  }
  set<pair<long long, int>> st;
  dist[1] = 0;
  st.insert({dist[1], 1});
  vector<int> res;
  while (k > 0 && !st.empty()) {
    auto cur = *st.begin();
    st.erase(cur);
    int u = cur.second;
    if (u != 1) {
      k--;
      res.push_back(mp[{parent[u], u}]);
    }
    for (auto &p : adj[u]) {
      if (dist[p.first] <= cur.first + p.second) continue;
      if (dist[p.first] != INF) st.erase({dist[p.first], p.first});
      dist[p.first] = cur.first + p.second;
      parent[p.first] = u;
      st.insert({dist[p.first], p.first});
    }
  }
  cout << res.size() << '\n';
  for (int i : res) cout << i << ' ';
  cout << '\n';
  return 0;
}
