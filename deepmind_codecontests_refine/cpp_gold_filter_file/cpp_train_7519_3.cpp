#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 20, INF = 1e9;
int d[N], dist[N][1005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, g, r;
  cin >> n >> m;
  for (int i = int(0); i < int(m); ++i) cin >> d[i];
  sort(d, d + m);
  cin >> g >> r;
  deque<pair<int, int> > dq;
  for (int i = int(0); i < int(N); ++i)
    for (int j = int(0); j < int(1005); ++j) dist[i][j] = INF;
  dist[0][0] = 0;
  dq.push_back(pair<int, int>(0, 0));
  int ans = INF;
  while (int(dq.size())) {
    pair<int, int> par = dq.front();
    dq.pop_front();
    int id = par.first, trav = par.second;
    if (id == m - 1)
      ans = min(ans, dist[id][trav] * (r + g) + trav - r * (trav == 0));
    if (id > 0) {
      int cost = d[id] - d[id - 1];
      if (trav + cost < g && dist[id - 1][trav + cost] == INF) {
        dist[id - 1][trav + cost] = dist[id][trav];
        dq.push_front(pair<int, int>(id - 1, trav + cost));
      } else if (trav + cost == g && dist[id - 1][0] == INF) {
        dist[id - 1][0] = dist[id][trav] + 1;
        dq.push_back(pair<int, int>(id - 1, 0));
      }
    }
    if (id + 1 < m) {
      int cost = d[id + 1] - d[id];
      if (trav + cost < g && dist[id + 1][trav + cost] == INF) {
        dist[id + 1][trav + cost] = dist[id][trav];
        dq.push_front(pair<int, int>(id + 1, trav + cost));
      } else if (trav + cost == g && dist[id + 1][0] == INF) {
        dist[id + 1][0] = dist[id][trav] + 1;
        dq.push_back(pair<int, int>(id + 1, 0));
      }
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}
