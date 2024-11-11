#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8 + 7;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;
char g[1010][1010];
int sx[3], sy[3];
deque<int> q;
int dis[1010][1010][3];
bool inrange(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
int ans = INF;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", &g[i]);
    for (int j = 0; j < m; j++)
      if (isdigit(g[i][j])) {
        sx[g[i][j] - '1'] = i;
        sy[g[i][j] - '1'] = j;
      }
  }
  for (int j = 0; j < n; j++)
    for (int k = 0; k < m; k++)
      for (int l = 0; l < 3; l++) dis[j][k][l] = INF;
  for (int i = 0; i < 3; i++) {
    dis[sx[i]][sy[i]][i] = 0;
    q.push_back(sx[i]), q.push_back(sy[i]);
    while (!q.empty()) {
      int cx = q.front();
      q.pop_front();
      int cy = q.front();
      q.pop_front();
      for (int k = 0; k < 4; k++) {
        int nx = cx + dx[k], ny = cy + dy[k];
        if (!inrange(nx, ny) || g[nx][ny] == '#') continue;
        if (dis[nx][ny][i] == INF) {
          if (g[nx][ny] == '.') {
            dis[nx][ny][i] = dis[cx][cy][i] + 1;
            q.push_back(nx), q.push_back(ny);
          } else {
            dis[nx][ny][i] = dis[cx][cy][i];
            q.push_front(ny), q.push_front(nx);
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int tmp = dis[i][j][0] + dis[i][j][1] + dis[i][j][2];
      if (g[i][j] == '.') tmp -= 2;
      ans = min(ans, tmp);
    }
  if (ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
