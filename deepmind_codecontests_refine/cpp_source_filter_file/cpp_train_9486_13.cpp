#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const long long INF = 1000000000000000000LL;
const int MAX_N = 3e5 + 5;
int n, m, k;
vector<pair<pair<int, int>, long long>> adjList[MAX_N];
vector<int> ans;
int idx[MAX_N];
void dijkstra(int start) {
  fill(idx, idx + MAX_N, -1);
  vector<long long> dist(MAX_N + 1, (1ll << 45));
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  pq.push({0, start});
  dist[start] = 0;
  int cc = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    long long d = pq.top().first;
    pq.pop();
    if (d > dist[u]) continue;
    if (cc < k && idx[u] != -1) {
      ans.push_back(idx[u]);
      ++cc;
    }
    for (auto edge : adjList[u]) {
      int v = edge.first.first;
      long long w = edge.second;
      if (dist[u] + w < dist[v]) {
        pq.push({dist[u] + w, v});
        dist[v] = dist[u] + w;
        idx[v] = edge.first.second;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adjList[u].push_back({{v, i + 1}, w});
    adjList[v].push_back({{u, i + 1}, w});
  }
  dijkstra(1);
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " \n"[i == ans.size() - 1];
  }
  return 0;
}
