#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long, long long>>> G(600000 + 5);
vector<long long> vis(600000 + 5, 0), DIST(600000 + 5, 1e15);
bool fun_x(pair<pair<long long, long long>, long long> a,
           pair<pair<long long, long long>, long long> b) {
  return a.first.first < b.first.first;
}
bool fun_y(pair<pair<long long, long long>, long long> a,
           pair<pair<long long, long long>, long long> b) {
  return a.first.second < b.first.second;
}
void dijkstra(long long node) {
  long long src = 0;
  set<pair<long long, long long>> pq;
  pq.insert({0, src});
  vis[0] = 1;
  DIST[0] = 0;
  while (!pq.empty()) {
    auto topp = *pq.begin();
    pq.erase(topp);
    long long node = topp.second, dist = topp.first;
    for (auto child : G[node]) {
      if (DIST[child.first] > (DIST[node] + child.second)) {
        pq.erase({DIST[child.first], child.first});
        DIST[child.first] = (DIST[node] + child.second);
        pq.insert({DIST[child.first], child.first});
      }
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t begin = clock();
  long long n, m;
  cin >> n >> m;
  long long sx, sy, dx, dy;
  cin >> sx >> sy >> dx >> dy;
  vector<pair<pair<long long, long long>, long long>> sort_x, sort_y;
  for (long long i = 1; i <= m; i++) {
    long long p, q;
    cin >> p >> q;
    sort_x.push_back({{p, q}, i});
    sort_y.push_back({{p, q}, i});
  }
  sort(sort_x.begin(), sort_x.end(), fun_x);
  sort(sort_y.begin(), sort_y.end(), fun_y);
  for (long long i = 1; i < m; i++) {
    long long prst_node = sort_x[i].second, prev_node = sort_x[i - 1].second;
    long long edge_val = sort_x[i].first.first - sort_x[i - 1].first.first;
    G[prst_node].push_back({prev_node, edge_val});
    G[prev_node].push_back({prst_node, edge_val});
  }
  for (long long i = 1; i < m; i++) {
    long long prst_node = sort_y[i].second, prev_node = sort_y[i - 1].second;
    long long edge_val = sort_y[i].first.second - sort_y[i - 1].first.second;
    G[prst_node].push_back({prev_node, edge_val});
    G[prev_node].push_back({prst_node, edge_val});
  }
  for (long long i = 0; i < m; i++) {
    long long prst_node = sort_x[i].second, prev_node = 0;
    long long edge_val =
        min(abs(sx - sort_x[i].first.first), abs(sy - sort_x[i].first.second));
    G[prst_node].push_back({prev_node, edge_val});
    G[prev_node].push_back({prst_node, edge_val});
  }
  for (long long i = 0; i < m; i++) {
    long long prst_node = sort_x[i].second, prev_node = m + 1;
    long long edge_val =
        abs(dx - sort_x[i].first.first) + abs(dy - sort_x[i].first.second);
    G[prst_node].push_back({prev_node, edge_val});
    G[prev_node].push_back({prst_node, edge_val});
  }
  for (long long i = 0; i < m; i++) {
    long long prst_node = sort_y[i].second, prev_node = 0;
    long long edge_val =
        min(abs(sx - sort_y[i].first.first), abs(sy - sort_y[i].first.second));
    G[prst_node].push_back({prev_node, edge_val});
    G[prev_node].push_back({prst_node, edge_val});
  }
  for (long long i = 0; i < m; i++) {
    long long prst_node = sort_y[i].second, prev_node = m + 1;
    long long edge_val =
        abs(dx - sort_y[i].first.first) + abs(dy - sort_y[i].first.second);
    G[prst_node].push_back({prev_node, edge_val});
    G[prev_node].push_back({prst_node, edge_val});
  }
  dijkstra(0);
  DIST[m + 1] = min(DIST[m + 1], abs(dy - sy) + abs(dx - sx));
  cout << DIST[m + 1] << '\n';
  return 0;
}
