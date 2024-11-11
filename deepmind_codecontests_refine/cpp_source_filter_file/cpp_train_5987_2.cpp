#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char mp[3][N], tmp[3][N], g[55][3][N];
bool vis[55][3][N];
int n, k;
void getNext(int id) {
  memcpy(g[id], mp, sizeof(mp));
  for (int i = int(0); i <= int((3) - 1); i++)
    for (int j = int(1); j <= int(n - 3); j++) tmp[i][j] = mp[i][j + 3];
  for (int i = int(0); i <= int((3) - 1); i++)
    tmp[i][n - 2] = tmp[i][n - 1] = tmp[i][n] = '.';
  memcpy(mp, tmp, sizeof(tmp));
}
int dx[] = {0, -1, 1}, dy[] = {0, 0, 0};
bool good(int now, int x, int y) {
  return x >= 0 && x < 3 && g[now][x][y] == '.' && g[now - 1][x][y + 1] == '.';
}
bool bfs(int sx, int sy) {
  memset(vis, 0, sizeof(vis));
  int now = 0, x = sx, y = sy;
  queue<int> q;
  q.push(now), q.push(x);
  while (q.size()) {
    now = q.front();
    q.pop();
    x = q.front();
    q.pop();
    if (now > 10) {
      return 1;
    }
    for (int i = int(0); i <= int((3) - 1); i++) {
      if (g[now][x][y + 1] != '.') continue;
      int tx = x + dx[i];
      if (good(now + 1, tx, y)) {
        if (!vis[now + 1][tx][y]) {
          q.push(now + 1), q.push(tx);
          vis[now + 1][tx][y] = 1;
        }
      }
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = int(0); i <= int((3) - 1); i++) {
      cin >> (mp[i] + 1);
    }
    int sx, sy;
    for (int i = int(0); i <= int((3) - 1); i++) {
      for (int j = int(1); j <= int(n); j++)
        if (mp[i][j] == 's') {
          sx = i, sy = j;
          mp[i][j] = '.';
        }
    }
    for (int i = int(0); i <= int((54) - 1); i++) getNext(i);
    if (bfs(sx, sy))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
