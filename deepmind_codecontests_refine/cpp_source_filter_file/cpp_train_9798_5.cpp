#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long sx, sy;
long long first, second;
char g[2010][2010];
long long dist[2010][2010];
deque<pair<long long, long long>> q;
long long dx[4] = {0, -1, 0, 1};
long long dy[4] = {1, 0, -1, 0};
long long dw[4] = {1, 0, 0, 0};
void dijkstra() {
  dist[sx][sy] = 0;
  q.push_front({sx, sy});
  while (q.size()) {
    auto t = q.front();
    q.pop_front();
    for (long long i = 0; i < 4; i++) {
      long long a = t.first + dx[i], b = t.second + dy[i];
      if (a > n || b > m || a < 1 || b < 1) continue;
      if (g[a][b] == '*') continue;
      if (dist[a][b] <= dist[t.first][t.second] + dw[i]) continue;
      dist[a][b] = dist[t.first][t.second] + dw[i];
      if (i)
        q.push_front({a, b});
      else
        q.push_back({a, b});
    }
  }
}
void solve() {
  cin >> n >> m >> sx >> sy >> first >> second;
  for (long long i = 1; i <= n; i++) cin >> g[i] + 1;
  memset(dist, 0x3f, sizeof dist);
  dijkstra();
  long long ans = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++)
      if (g[i][j] == '.')
        if (dist[i][j] <= second)
          if (dist[i][j] - j <= first) ans++;
  cout << ans << endl;
}
signed main() {
  solve();
  return 0;
}
