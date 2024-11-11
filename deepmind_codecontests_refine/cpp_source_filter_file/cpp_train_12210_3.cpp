#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, INF = 1e9 + 5;
int n, m, k, dist[N][N], x, y, ans = INF, tmpans;
bool vis[N][N];
struct Edge {
  int a, b, w;
};
Edge edges[N];
vector<pair<int, int>> graph[N];
pair<int, int> routes[N];
void dijkstra(int vv) {
  fill(dist[vv], dist[vv] + N, INF);
  dist[vv][vv] = 0;
  priority_queue<pair<int, int>> pq;
  pq.push({0, vv});
  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    if (!vis[vv][v]) {
      vis[vv][v] = true;
      for (auto p : graph[v]) {
        if (dist[vv][v] + p.second < dist[vv][p.first]) {
          dist[vv][p.first] = dist[vv][v] + p.second;
          pq.push({dist[vv][p.first], p.first});
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> edges[i].a >> edges[i].b >> edges[i].w;
    graph[edges[i].a].push_back({edges[i].b, edges[i].w});
    graph[edges[i].b].push_back({edges[i].a, edges[i].w});
  }
  for (int i = 0; i < k; i++) cin >> routes[i].first >> routes[i].second;
  for (int i = 1; i <= n; i++) dijkstra(i);
  for (int e = 0; e < m; e++) {
    tmpans = 0;
    for (int i = 0; i < k; i++) {
      x = routes[i].first, y = routes[i].second;
      tmpans += min({dist[x][edges[e].a] + dist[y][edges[e].b],
                     dist[x][edges[e].b] + dist[y][edges[e].a], dist[x][y]});
    }
    ans = min(ans, tmpans);
  }
  cout << ans;
}
