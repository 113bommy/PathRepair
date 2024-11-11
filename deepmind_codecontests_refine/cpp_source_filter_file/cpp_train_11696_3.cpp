#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const int MAXN = 1e5 + 10;
const long long mod = 1e9 + 7;
using namespace std;
char mp[3500][3500];
bool vis[3200][3200];
int n, m, sx, sy;
int que[3020 * 3020];
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
bool bfs() {
  memset(vis, false, sizeof(vis));
  int ft = 0, ed = 0;
  que[ed++] = sx, que[ed++] = sy;
  vis[sx][sy] = true;
  while (ft < ed) {
    int x = que[ft++];
    int y = que[ft++];
    for (int i = 0; i < 4; i++) {
      int nx = x + dir[i][0];
      int ny = y + dir[i][1];
      if (nx <= 0)
        nx += 2 * n;
      else if (nx >= 2 * n + 1)
        nx -= 2 * n;
      if (ny <= 0)
        ny += 2 * m;
      else if (ny >= 2 * m + 1)
        ny -= x * m;
      if (nx >= 1 && nx <= 2 * n && ny >= 1 && ny <= 2 * m &&
          vis[nx][ny] == false && mp[nx][ny] == '.') {
        vis[nx][ny] = true;
        que[ed++] = nx, que[ed++] = ny;
        int basex = nx, basey = ny;
        int cnt = 0;
        if (basex > n) basex -= n;
        if (basey > m) basey -= m;
        if (vis[basex][basey]) cnt++;
        if (vis[basex + n][basey]) cnt++;
        if (vis[basex + n][basey + m]) cnt++;
        if (vis[basex][basey + m]) cnt++;
        if (cnt >= 2) return true;
      }
    }
  }
  return false;
}
int main(void) {
  n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", mp[i] + 1);
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == 'S') {
        sx = i, sy = j;
        mp[i][j] = '.';
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      mp[i + n][j] = mp[i][j];
      mp[i + n][j + m] = mp[i][j];
      mp[i][j + m] = mp[i][j];
    }
  }
  if (bfs())
    printf("Yes\n");
  else
    printf("No\n");
}
