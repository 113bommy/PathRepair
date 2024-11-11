#include <bits/stdc++.h>
using namespace std;
int f[8][8][8][8];
int x, y, xx, yy, ans;
char st[8][8];
int dx[] = {2, 2, -2, -2};
int dy[] = {2, -2, 2, -2};
int cheak(int x, int y) {
  if (x >= 0 && x < 8 && y >= 0 && y < 8) return 1;
  return 0;
}
void dfs(int x, int y, int xx, int yy) {
  if (ans) return;
  if (f[x][y][xx][yy]) return;
  f[x][y][xx][yy] = 1;
  if ((x == xx && y == yy) && st[x][y] != '#') {
    ans = 1;
    return;
  }
  for (int t1 = 0; t1 < 4; t1++) {
    int x1 = x + dx[t1], y1 = y + dy[t1];
    if (!cheak(x1, y1)) continue;
    for (int t2 = 0; t2 < 4; t2++) {
      int x2 = xx + dx[t2], y2 = yy + dy[t2];
      if (!cheak(x2, y2)) continue;
      dfs(x1, y1, x2, y2);
    }
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(f, 0, sizeof(f));
    x = -1;
    for (int i = 0; i < 8; i++) scanf("%s", st[i]);
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        if (st[i][j] == 'K') {
          if (x == -1) {
            x = i;
            y = j;
          } else {
            xx = i;
            yy = j;
          }
        }
    ans = 0;
    dfs(x, y, xx, yy);
    if (ans)
      puts("YES");
    else
      puts("NO");
  }
}
