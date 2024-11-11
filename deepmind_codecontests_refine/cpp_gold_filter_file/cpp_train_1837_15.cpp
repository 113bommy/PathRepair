#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int n, m, r, k;
inline long long getcnt(int x, int y) {
  return 1LL * (min(x, r - 1) + min(n - x - 1, r - 1) - r + 2) *
         (min(y, r - 1) + min(m - y - 1, r - 1) - r + 2);
}
int main() {
  cin >> n >> m >> r >> k;
  priority_queue<pair<long long, pair<int, int>>> pq;
  set<pair<int, int>> vis;
  pq.push({getcnt(n / 2, m / 2), {n / 2, m / 2}});
  vis.insert({n / 2, m / 2});
  long long ans = 0;
  for (int i = 0; i < k && !pq.empty(); i++) {
    auto pp = pq.top();
    pq.pop();
    ans += pp.first;
    auto p = pp.second;
    ;
    ;
    for (int j = 0; j < 4; j++) {
      int nx = p.first + dx[j];
      int ny = p.second + dy[j];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
          vis.find(make_pair(nx, ny)) != vis.end())
        continue;
      ;
      pq.push({getcnt(nx, ny), {nx, ny}});
      vis.insert({nx, ny});
    }
  }
  printf("%.11f\n", 1.0 * ans / (n - r + 1) / (m - r + 1));
  return 0;
}
