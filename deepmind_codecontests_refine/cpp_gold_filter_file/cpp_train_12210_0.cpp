#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int mat[1001][1001] = {};
vector<vector<pair<int, int>>> adj;
vector<int> dist;
void dijkstra(int s, int n) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push(make_pair(0, s));
  for (int i = 0; i < n; i++) dist[i] = INF;
  dist[s] = 0;
  while (!pq.empty()) {
    pair<int, int> node = pq.top();
    pq.pop();
    for (auto child : adj[node.second]) {
      int v = child.second;
      int nwt = dist[node.second] + child.first;
      if (dist[v] > nwt) {
        dist[v] = nwt;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}
int getDist(int a, int b) {
  if (a > b) return mat[b][a];
  if (a < b) return mat[a][b];
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  int n, m, k;
  cin >> n >> m >> k;
  adj.resize(n);
  vector<int> edges[m];
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(make_pair(w, y - 1));
    adj[y - 1].push_back(make_pair(w, x - 1));
    ;
    edges[i].push_back(x - 1);
    edges[i].push_back(y - 1);
    edges[i].push_back(w);
  }
  vector<pair<int, int>> couriers;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    pair<int, int> p = make_pair(x - 1, y - 1);
    couriers.push_back(p);
  }
  dist.resize(n, INF);
  for (int i = 0; i < n; i++) {
    dijkstra(i, n);
    for (int j = 0; j < n; j++) mat[i][j] = dist[j];
  }
  int mn = INF;
  for (int i = 0; i < m; i++) {
    int ans = 0;
    int a = edges[i][0];
    int b = edges[i][1];
    for (int j = 0; j < k; j++) {
      int x = min(couriers[j].first, couriers[j].second);
      int y = max(couriers[j].first, couriers[j].second);
      int distance = getDist(x, y);
      if (getDist(x, a) + getDist(y, b) < distance)
        distance = getDist(x, a) + getDist(y, b);
      if (getDist(x, b) + getDist(y, a) < distance)
        distance = getDist(x, b) + getDist(y, a);
      ans += distance;
    }
    if (mn > ans) {
      mn = ans;
    }
  }
  cout << mn << endl;
}
