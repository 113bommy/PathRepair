#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int inf = (int)1e9;
const int MAX_N = 100 * 1000 + 1000;
int n, m, k;
int s, t;
bool is_vol[MAX_N];
vector<int> adj[MAX_N];
int dist[MAX_N];
vector<pair<int, int> > q;
bool dijkstra(int lim) {
  if (s == t) return 1;
  q.clear();
  memset(dist, -1, sizeof dist);
  dist[s] = lim;
  q.push_back(pair<int, int>(s, lim));
  for (int head = 0; head < ((int)q.size()); head++) {
    int here = q[head].first;
    int cost = q[head].second;
    if (cost != dist[here] || cost == 0) continue;
    for (int i = 0; i < ((int)adj[here].size()); i++) {
      int next = adj[here][i];
      int ncost = cost - 1;
      if (is_vol[next]) ncost = lim;
      if (ncost > dist[next]) {
        dist[next] = ncost;
        q.push_back(pair<int, int>(next, dist[next]));
        if (next == t) return 1;
      }
    }
  }
  return 0;
}
int main() {
  q.reserve(2 * MAX_N);
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    is_vol[x] = 1;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cin >> s >> t;
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (dijkstra(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  if (lo == n) lo = -1;
  cout << lo << endl;
  return 0;
}
