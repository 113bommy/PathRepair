#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, r, k;
  cin >> n >> m >> r >> k;
  priority_queue<pair<int, pair<int, int>>> q;
  int sx = (n + 1) / 2, sy = (m + 1) / 2;
  auto cost = [&](int x, int y) {
    return (min(n + 1, x + r) - max(x, r)) * (min(m + 1, y + r) - max(y, r));
  };
  q.push({cost(sx, sy), {sx, sy}});
  double ans = 0;
  vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
  set<pair<int, int>> vis;
  vis.insert({sx, sy});
  while (k-- && q.size()) {
    auto [c, tmp] = q.top();
    q.pop();
    auto [x, y] = tmp;
    ans += c;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m ||
          vis.find({nx, ny}) != vis.end())
        continue;
      q.push({cost(nx, ny), {nx, ny}});
      vis.insert({nx, ny});
    }
  }
  cout << fixed << setprecision(10) << ans / ((n - r + 1) * (m - r + 1))
       << "\n";
}
