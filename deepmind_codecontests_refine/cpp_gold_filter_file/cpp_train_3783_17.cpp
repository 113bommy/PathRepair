#include <bits/stdc++.h>
using namespace std;
void read(int &k) {
  k = 0;
  char x = getchar();
  while (x < '0' || x > '9') x = getchar();
  while (x >= '0' && x <= '9') {
    k = k * 10 - 48 + x;
    x = getchar();
  }
}
int n, m, a[510][510], b[510][510], c[510][510], now, ans, nx, ny;
void goup(int &x, int &y, int len) {
  now += c[x - 1][y] - c[x - len - 1][y];
  x -= len;
}
void godown(int &x, int &y, int len) {
  now += c[x + len][y] - c[x][y];
  x += len;
}
void goleft(int &x, int &y, int len) {
  now += b[x][y - 1] - b[x][y - len - 1];
  y -= len;
}
void goright(int &x, int &y, int len) {
  now += b[x][y + len] - b[x][y];
  y += len;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      b[i][j] = b[i][j - 1] + a[i][j];
      c[i][j] = c[i - 1][j] + a[i][j];
    }
  ans = -1000000000;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      now = a[i][j];
      nx = i;
      ny = j;
      for (int st = 4; i - st / 2 >= 1 && i + st / 2 <= n && j - st / 2 >= 1 &&
                       j + st / 2 <= m;
           st += 4) {
        goleft(nx, ny, 2);
        godown(nx, ny, st - 2);
        goright(nx, ny, st);
        goup(nx, ny, st);
        goleft(nx, ny, st);
        if (now > ans) ans = now;
      }
      if (i >= 3 && j + 2 <= m) {
        now = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 2] +
              a[i - 2][j + 2] + a[i - 2][j + 1] + a[i - 2][j];
        if (now > ans) ans = now;
        nx = i - 2;
        ny = j;
        for (int st = 6; i - st / 2 - 1 >= 1 && i + st / 2 - 1 <= n &&
                         j - st / 2 + 1 >= 1 && j + st / 2 + 1 <= m;
             st += 4) {
          goleft(nx, ny, 2);
          godown(nx, ny, st - 2);
          goright(nx, ny, st);
          goup(nx, ny, st);
          goleft(nx, ny, st);
          if (now > ans) ans = now;
        }
      }
    }
  cout << ans << endl;
  return 0;
}
