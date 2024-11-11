#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
const int INF = 1e8;
int dis[3][MAXN][MAXN];
char grid[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m, ans = INF;
deque<pair<int, int> > q;
void bfs(int s) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) dis[s][i][j] = INF;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (grid[i][j] == (s + '0') + 1) {
        q.push_back(make_pair(i, j));
        dis[s][i][j] = 0;
      }
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop_front();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (dis[s][nx][ny] != INF || grid[nx][ny] == '#') continue;
      if (nx < 0 || nx >= n || ny < 0 || nx >= m) continue;
      int cost = (grid[nx][ny] == '.');
      dis[s][nx][ny] = dis[s][x][y] + cost;
      if (cost)
        q.push_back(make_pair(nx, ny));
      else
        q.push_front(make_pair(nx, ny));
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> grid[i][j];
  for (int i = 0; i < 3; ++i) bfs(i);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      int cur = dis[0][i][j] + dis[1][i][j] + dis[2][i][j];
      if (grid[i][j] == '.') cur -= 2;
      ans = min(ans, cur);
    }
  if (ans >= INF) ans = -1;
  cout << ans << endl;
  return 0;
}
