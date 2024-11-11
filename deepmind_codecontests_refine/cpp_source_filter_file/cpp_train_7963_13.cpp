#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1111;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int dist[1005][1005][3], n, m;
char c[1005][1005];
queue<pair<int, int> > q;
void bfs(int k) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (c[i][j] == '1' + k) {
        q.push(make_pair(i, j));
        dist[i][j][k] = 0;
      }
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (0 <= nx && nx < n && 0 <= ny && ny < m && dist[nx][ny][k] == inf &&
          c[nx][ny] == '.') {
        dist[nx][ny][k] = dist[x][y][k] + 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
      for (int k = 0; k < 3; k++) dist[i][j][k] = inf;
    }
  bfs(0);
  bfs(1);
  bfs(2);
  int d12 = inf, d13 = inf, d23 = inf, d123 = inf;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (c[i][j] != '#') {
        d12 = min(d12, dist[i][j][0] + dist[i][j][1] - 1);
        d13 = min(d13, dist[i][j][0] + dist[i][j][2] - 1);
        d23 = min(d23, dist[i][j][1] + dist[i][j][2] - 1);
        d123 = min(d123, dist[i][j][0] + dist[i][j][1] + dist[i][j][2] - 2);
      }
  int ans = min(
      d123, min(d12 + d13, min(d12 + d23, min(d13 + d23, d12 + d13 + d23))));
  if (ans > 1000 * 1000)
    puts("-1");
  else
    cout << ans;
  return 0;
}
