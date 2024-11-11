#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int n, m, a, b, w;
vector<pair<int, int>> adj[maxN];
vector<int> path;
long long dist[maxN];
set<pair<long long, int>> q;
int par[maxN];
void read_input() {
  cin >> n >> m;
  while (m--) {
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }
}
void dijkstra() {
  memset(dist, 63, sizeof dist);
  q.insert({dist[1] = 0, 1});
  while (!q.empty()) {
    int u = q.begin()->second;
    for (auto v : adj[u]) {
      if (dist[v.first] > dist[u] + v.second) {
        q.erase({dist[v.first], v.first});
        q.insert({dist[v.first] = dist[u] + v.second, v.first});
        par[v.first] = u;
      }
    }
    q.erase(q.begin());
  }
}
void solve() {
  dijkstra();
  if (dist[n] > 1e12)
    cout << -1;
  else {
    while (n != 1) {
      path.push_back(n);
      n = par[n];
    }
    cout << 1 << ' ';
    for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << ' ';
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve();
  return 0;
}
