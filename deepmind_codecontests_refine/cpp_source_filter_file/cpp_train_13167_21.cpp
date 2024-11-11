#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int m, n, i, f = 0, j, ans = 0, k, x, r, l, t, u, v;
  cin >> n >> m;
  vector<vector<pair<long long int, long long int>>> adj(n + 1);
  map<pair<long long int, long long int>, long long int> edges;
  for (i = 0; i < m; ++i) {
    cin >> u >> v >> x;
    adj[u].push_back({v, x});
    adj[v].push_back({u, x});
    if (u < v)
      edges[{u, v}] = i + 1;
    else
      edges[{v, u}] = i + 1;
  }
  long long int start;
  cin >> start;
  priority_queue<pair<long long int, long long int>> q;
  vector<long long int> d(n + 1, 1e18), addw(n + 1, 1e18), parent(n + 1, -1);
  d[start] = 0;
  addw[start] = 0;
  q.push({0, start});
  pair<long long int, long long int> temp;
  while (!q.empty()) {
    temp = q.top();
    q.pop();
    for (auto h : adj[temp.second]) {
      if (d[h.first] > d[temp.second] + h.second) {
        d[h.first] = d[temp.second] + h.second;
        q.push({-d[h.first], h.first});
        addw[h.first] = h.second;
        parent[h.first] = temp.second;
      } else if (d[h.first] == d[temp.second] + h.second) {
        if (addw[h.first] > h.second) {
          addw[h.first] = h.second;
          parent[h.first] = temp.second;
        }
      }
    }
  }
  vector<long long int> res;
  for (i = 1; i <= m; ++i) {
    ans += addw[i];
    if (parent[i] != -1) {
      if (i < parent[i]) {
        res.push_back(edges[{i, parent[i]}]);
      } else {
        res.push_back(edges[{parent[i], i}]);
      }
    }
  }
  cout << ans << endl;
  for (i = 0; i < res.size(); ++i) cout << res[i] << " ";
  return 0;
}
