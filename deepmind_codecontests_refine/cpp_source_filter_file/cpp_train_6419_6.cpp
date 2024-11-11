#include <bits/stdc++.h>
using namespace std;
const long long oo = (long long)1e18;
const int N = 1001;
vector<pair<int, int> > adjd[N], adjc[N];
bool vis[N];
long long dis[N];
pair<int, int> val[N];
int n, m, x, y;
void dijkstra(int u, bool stat) {
  for (int i = 1; i <= n; i++) dis[i] = oo, vis[i] = false;
  dis[u] = 0;
  priority_queue<pair<long long, int> > pq;
  pq.push({0, u});
  while (!pq.empty()) {
    int node = pq.top().second;
    pq.pop();
    if (vis[node]) continue;
    vis[node] = true;
    for (const auto& edge : ((stat) ? adjd[node] : adjc[node])) {
      if (dis[node] + edge.second < dis[edge.first]) {
        dis[edge.first] = dis[node] + edge.second;
        pq.push({-dis[edge.first], edge.first});
      }
    }
  }
  if (stat) {
    for (int i = 1; i <= n; i++) {
      if (dis[i] <= val[u].first) {
        adjc[u].push_back({i, val[u].second});
      }
    }
  }
}
int main() {
  scanf("%d %d %d %d", &n, &m, &x, &y);
  while (m--) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    adjd[u].push_back({v, w});
    adjd[v].push_back({u, w});
  }
  for (int i = 1; i <= n; i++) {
    int d, c;
    scanf("%d %d", &d, &c);
    val[i] = {d, c};
  }
  for (int i = 1; i <= n; i++) {
    dijkstra(i, true);
  }
  dijkstra(x, false);
  if (dis[y] >= oo) {
    printf("-1\n");
  } else {
    printf("%d\n", dis[y]);
  }
}
