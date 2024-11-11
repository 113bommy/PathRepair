#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int n, m, x, y, w, i, t, length, u;
  cin >> n >> m;
  vector<vector<pair<unsigned long long int, unsigned long long int>>> adj(n);
  vector<unsigned long long int> dist(n, 1e9);
  while (m--)
    scanf(" %llu%llu%llu", &x, &y, &w), adj[x - 1].push_back({y - 1, 2 * w}),
        adj[y - 1].push_back({x - 1, 2 * w});
  priority_queue<pair<unsigned long long int, unsigned long long int>,
                 vector<pair<unsigned long long int, unsigned long long int>>,
                 greater<pair<unsigned long long int, unsigned long long int>>>
      q;
  for (i = 0; i < n; i++) scanf(" %llu", &w), q.push({w, i});
  while (!q.empty()) {
    pair<unsigned long long int, unsigned long long int> p = q.top();
    q.pop();
    u = p.second, length = p.first;
    if (length > dist[u])
      continue;
    else
      dist[u] = length;
    for (i = 0; i < adj[u].size(); i++) {
      pair<unsigned long long int, unsigned long long int> l = adj[u][i];
      w = l.second, t = l.first;
      if (dist[u] + w < dist[t]) q.push({dist[u] + w, t});
    }
  }
  for (i = 0; i < n; i++) printf("%llu ", dist[i]);
  return 0;
}
