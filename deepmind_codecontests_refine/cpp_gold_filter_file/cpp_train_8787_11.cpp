#include <bits/stdc++.h>
const double pi = acos(-1.0), eps = 1e-9;
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int MO = (int)(1e9 + 7);
using namespace std;
queue<int> Q;
int dis[61][61], vis[61][61];
int n, m, ans = 1 << 30;
char s[61][61];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      memset(dis, 0x3f, sizeof(dis));
      memset(vis, 0, sizeof(vis));
      Q.push(i);
      Q.push(j);
      vis[i][j] = true;
      dis[i][j] = 1;
      while (Q.size()) {
        int x = Q.front();
        Q.pop();
        int y = Q.front();
        Q.pop();
        vis[x][y] = false;
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d], ny = y + dy[d];
          if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
          int dd = dis[x][y] + (s[x][y] != s[nx][ny]);
          if (dd < dis[nx][ny]) {
            dis[nx][ny] = dd;
            if (!vis[nx][ny]) {
              Q.push(nx);
              Q.push(ny);
              vis[nx][ny] = true;
            }
          }
        }
      }
      int t = 0;
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
          if (s[i][j] == 'B' && dis[i][j] > t) t = dis[i][j];
      ans = min(ans, t);
    }
  cout << ans << endl;
}
