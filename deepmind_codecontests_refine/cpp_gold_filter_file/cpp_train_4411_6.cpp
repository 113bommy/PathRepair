#include <bits/stdc++.h>
using namespace std;
long long int inf = 2e9;
const int N = 1e5;
vector<pair<int, int>> tree[N + 1];
vector<int> dlay[N + 1];
long long int dist[N + 1];
priority_queue<pair<int, int>> pq;
int n, m;
int solve() {
  for (int i = 0; i <= N; i++) dist[i] = inf;
  dist[1] = 0;
  pq.push(make_pair(-0, 1));
  while (pq.size()) {
    int d = -pq.top().first;
    int y = pq.top().second;
    pq.pop();
    if (dist[y] < d) continue;
    if (y == n) return d;
    for (int i = 0; i < dlay[y].size(); i++)
      if (d == dlay[y][i]) d++;
    for (int i = 0; i < tree[y].size(); i++) {
      int u = tree[y][i].first;
      int l = tree[y][i].second;
      if (l + d < dist[u]) {
        dist[u] = l + d;
        pq.push(make_pair(-dist[u], u));
      }
    }
  }
  return -1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, d;
    cin >> x >> y >> d;
    tree[x].push_back({y, d});
    tree[y].push_back({x, d});
  }
  for (int i = 1; i <= n; i++) {
    int z;
    cin >> z;
    dlay[i].resize(z);
    for (int j = 0; j < z; j++) cin >> dlay[i][j];
  }
  cout << solve();
  return 0;
}
