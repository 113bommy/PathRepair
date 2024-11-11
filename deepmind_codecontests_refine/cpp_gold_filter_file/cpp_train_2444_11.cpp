#include <bits/stdc++.h>
using namespace std;
char mp[100][100];
int vis[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int flag, n, m, sx, sy;
int check(int x, int y, char c) {
  if (x >= 0 and x < n and y >= 0 and y < m and mp[x][y] == c) return 1;
  return 0;
}
void DFS(int x, int y, int sx, int sy) {
  char c = mp[x][y];
  if (flag) return;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (check(xx, yy, c) and (xx != sx or yy != sy)) {
      if (vis[xx][yy]) {
        flag = 1;
        return;
      }
      vis[xx][yy] = 1;
      DFS(xx, yy, x, y);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> mp[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) DFS(i, j, -1, -1);
      if (flag) break;
    }
  if (flag)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
