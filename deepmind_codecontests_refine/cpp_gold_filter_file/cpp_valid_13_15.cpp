#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
char ans[N][N];
bool cc[7];
int n, m, k;
void draw_right(int x, int y) {
  for (int i = 0; i < 7; i++) cc[i] = 0;
  for (int i = 0; i < 4; i++) {
    int xx = dx[i] + x, yy = dy[i] + y;
    if (xx > n || xx < 1 || yy > m || yy < 1 || ans[xx][yy] == '@') continue;
    cc[ans[xx][yy] - 'a'] = 1;
  }
  for (int i = 0; i < 4; i++) {
    int xx = dx[i] + x, yy = dy[i] + y + 1;
    if (xx > n || xx < 1 || yy > m || yy < 1 || ans[xx][yy] == '@') continue;
    cc[ans[xx][yy] - 'a'] = 1;
  }
  char ch;
  for (int i = 0; i < 7; i++)
    if (!cc[i]) {
      ch = i + 'a';
      break;
    }
  ans[x][y] = ans[x][y + 1] = ch;
}
void draw_down(int x, int y) {
  for (int i = 0; i < 7; i++) cc[i] = 0;
  for (int i = 0; i < 4; i++) {
    int xx = dx[i] + x, yy = dy[i] + y;
    if (xx > n || xx < 1 || yy > m || yy < 1 || ans[xx][yy] == '@') continue;
    cc[ans[xx][yy] - 'a'] = 1;
  }
  for (int i = 0; i < 4; i++) {
    int xx = dx[i] + x + 1, yy = dy[i] + y;
    if (xx > n || xx < 1 || yy > m || yy < 1 || ans[xx][yy] == '@') continue;
    cc[ans[xx][yy] - 'a'] = 1;
  }
  char ch;
  for (int i = 0; i < 7; i++)
    if (!cc[i]) {
      ch = i + 'a';
      break;
    }
  ans[x][y] = ans[x + 1][y] = ch;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) ans[i][j] = '@';
    bool c;
    if (n % 2 == 1) {
      int res = m / 2;
      if (k >= res && (k - res) % 2 == 0)
        c = 1;
      else
        c = 0;
      for (int i = 1; i <= m; i += 2) draw_right(n, i);
      res = k - res;
      for (int i = 1; i <= n; i += 2) {
        if (res == 0) break;
        for (int j = 1; j <= m; j += 2) {
          draw_right(i, j);
          draw_right(i + 1, j);
          res -= 2;
          if (res == 0) break;
        }
      }
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
          if (ans[i][j] == '@') draw_down(i, j);
    } else if (m % 2 == 1) {
      if (k <= n * m / 2 - n / 2 && k % 2 == 0)
        c = 1;
      else
        c = 0;
      for (int i = 1; i <= n; i += 2) draw_down(i, m);
      int res = k;
      for (int i = 1; i <= n; i += 2) {
        if (res == 0) break;
        for (int j = 1; j <= m - 1; j += 2) {
          draw_right(i, j);
          draw_right(i + 1, j);
          res -= 2;
          if (res == 0) break;
        }
      }
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
          if (ans[i][j] == '@') draw_down(i, j);
    } else {
      if (k % 2 == 0)
        c = 1;
      else
        c = 0;
      int res = k;
      for (int i = 1; i <= n; i += 2) {
        if (res == 0) break;
        for (int j = 1; j <= m; j += 2) {
          draw_right(i, j);
          draw_right(i + 1, j);
          res -= 2;
          if (res == 0) break;
        }
      }
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
          if (ans[i][j] == '@') draw_down(i, j);
    }
    puts(c ? "YES" : "NO");
    if (c) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) printf("%c", ans[i][j]);
        puts("");
      }
    }
  }
  return 0;
}
