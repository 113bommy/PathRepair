#include <bits/stdc++.h>
using namespace std;
const int Maxn = 210;
int vis[10][Maxn][Maxn], xi[10][Maxn][Maxn], xj[10][Maxn][Maxn];
void ycl() {
  for (int i = 25; i <= 200; i++)
    for (int j = 0; j <= 200; j++) {
      if (j > i) continue;
      if (i == 25 && j < 24)
        vis[1][i][j] = 1;
      else if (i > 25 && j == i - 2)
        vis[1][i][j] = 1;
    }
  for (int i = 50; i <= 200; i++)
    for (int j = 0; j <= 200; j++) {
      for (int k = 0; k <= j && k < 24; k++)
        if (vis[1][i - 25][j - k]) {
          vis[2][i][j] = 1;
          xi[2][i][j] = 25;
          xj[2][i][j] = k;
          break;
        }
      if (vis[2][i][j]) continue;
      for (int k = 26; k <= i && k <= j + 2; k++)
        if (vis[1][i - k][j - k + 2]) {
          vis[2][i][j] = 1;
          xi[2][i][j] = k;
          xj[2][i][j] = k - 2;
          break;
        }
    }
  for (int i = 65; i <= 200; i++)
    for (int j = 0; j <= 200; j++) {
      for (int k = 0; k <= j && k < 14; k++)
        if (vis[2][i - 15][j - k]) {
          vis[3][i][j] = 1;
          xi[3][i][j] = 15;
          xj[3][i][j] = k;
          break;
        }
      if (vis[3][i][j]) continue;
      for (int k = 16; k <= i && k <= j + 2; k++)
        if (vis[2][i - k][j - k + 2]) {
          vis[3][i][j] = 1;
          xi[3][i][j] = k;
          xj[3][i][j] = k - 2;
          break;
        }
    }
  for (int i = 65; i <= 200; i++)
    for (int j = 25; j <= 200; j++) {
      for (int k = 0; k < 24; k++)
        if (vis[3][i - k][j - 25]) {
          vis[4][i][j] = 1;
          xi[4][i][j] = k;
          xj[4][i][j] = 25;
          break;
        }
      if (vis[4][i][j]) continue;
      for (int k = 26; k <= i + 2 && k <= j; k++)
        if (vis[3][i - k + 2][j - k]) {
          vis[4][i][j] = 1;
          xi[4][i][j] = k - 2;
          xj[4][i][j] = k;
          break;
        }
    }
  for (int i = 65; i <= 200; i++)
    for (int j = 50; j <= 200; j++) {
      for (int k = 0; k < 24; k++)
        if (vis[4][i - k][j - 25]) {
          vis[5][i][j] = 1;
          xi[5][i][j] = k;
          xj[5][i][j] = 25;
          break;
        }
      if (vis[5][i][j]) continue;
      for (int k = 26; k <= i + 2 && k <= j; k++)
        if (vis[4][i - k + 2][j - k]) {
          vis[5][i][j] = 1;
          xi[5][i][j] = k - 2;
          xj[5][i][j] = k;
          break;
        }
    }
  for (int i = 75; i <= 200; i++)
    for (int j = 0; j <= 200; j++) {
      for (int k = 0; k <= j && k < 23; k++)
        if (vis[2][i - 25][j - k]) {
          vis[6][i][j] = 1;
          xi[6][i][j] = 25;
          xj[6][i][j] = k;
          break;
        }
      if (vis[6][i][j]) continue;
      for (int k = 26; k <= i && k <= j + 2; k++)
        if (vis[2][i - k][j - k + 2]) {
          vis[6][i][j] = 1;
          xi[6][i][j] = k;
          xj[6][i][j] = k - 2;
          break;
        }
    }
  for (int i = 75; i <= 200; i++)
    for (int j = 25; j <= 200; j++) {
      for (int k = 0; k < 24; k++)
        if (vis[6][i - k][j - 25]) {
          vis[7][i][j] = 1;
          xi[7][i][j] = k;
          xj[7][i][j] = 25;
          break;
        }
      if (vis[7][i][j]) continue;
      for (int k = 26; k <= i + 2 && k <= j; k++)
        if (vis[6][i - k + 2][j - k]) {
          vis[7][i][j] = 1;
          xi[7][i][j] = k - 2;
          xj[7][i][j] = k;
          break;
        }
    }
}
int main() {
  int t, x, y;
  scanf("%d", &t);
  ycl();
  while (t--) {
    scanf("%d%d", &x, &y);
    if (!(vis[6][x][y] || vis[7][x][y] || vis[5][x][y] || vis[6][y][x] ||
          vis[7][y][x] || vis[5][y][x])) {
      puts("Impossible");
      continue;
    }
    if (vis[6][x][y]) {
      puts("3:0");
      int tx = xi[6][x][y], ty = xj[6][x][y];
      printf("%d:%d ", tx, ty);
      x -= tx, y -= ty;
      tx = xi[2][x][y], ty = xj[2][x][y];
      printf("%d:%d ", tx, ty);
      x -= tx, y -= ty;
      printf("%d:%d\n", x, y);
      continue;
    }
    if (vis[7][x][y]) {
      puts("3:1");
      int tx = xi[7][x][y], ty = xj[7][x][y];
      printf("%d:%d ", tx, ty);
      x -= tx, y -= ty;
      tx = xi[6][x][y], ty = xj[6][x][y];
      printf("%d:%d ", tx, ty);
      x -= tx, y -= ty;
      tx = xi[2][x][y], ty = xj[2][x][y];
      printf("%d:%d ", tx, ty);
      x -= tx, y -= ty;
      printf("%d:%d\n", x, y);
      continue;
    }
    if (vis[5][x][y]) {
      puts("3:2");
      int tx = xi[5][x][y], ty = xj[5][x][y];
      printf("%d:%d ", tx, ty);
      x -= tx, y -= ty;
      tx = xi[4][x][y], ty = xj[4][x][y];
      printf("%d:%d ", tx, ty);
      x -= tx, y -= ty;
      int ttx = xi[3][x][y], tty = xj[3][x][y];
      x -= ttx, y -= tty;
      tx = xi[2][x][y], ty = xj[2][x][y];
      printf("%d:%d ", tx, ty);
      x -= tx, y -= ty;
      printf("%d:%d ", x, y);
      printf("%d:%d\n", ttx, tty);
      continue;
    }
    if (vis[5][y][x]) {
      puts("2:3");
      swap(x, y);
      int tx = xi[5][x][y], ty = xj[5][x][y];
      printf("%d:%d ", ty, tx);
      x -= tx, y -= ty;
      tx = xi[4][x][y], ty = xj[4][x][y];
      printf("%d:%d ", ty, tx);
      x -= tx, y -= ty;
      int ttx = xi[3][x][y], tty = xj[3][x][y];
      x -= ttx, y -= tty;
      tx = xi[2][x][y], ty = xj[2][x][y];
      printf("%d:%d ", ty, tx);
      x -= tx, y -= ty;
      printf("%d:%d ", y, x);
      printf("%d:%d\n", tty, ttx);
      continue;
    }
    if (vis[7][y][x]) {
      puts("1:3");
      swap(x, y);
      int tx = xi[7][x][y], ty = xj[7][x][y];
      printf("%d:%d ", ty, tx);
      x -= tx, y -= ty;
      tx = xi[6][x][y], ty = xj[6][x][y];
      printf("%d:%d ", ty, tx);
      x -= tx, y -= ty;
      tx = xi[2][x][y], ty = xj[2][x][y];
      printf("%d:%d ", ty, tx);
      x -= tx, y -= ty;
      printf("%d:%d\n", y, x);
      continue;
    }
    if (vis[6][y][x]) {
      puts("0:3");
      swap(x, y);
      int tx = xi[6][x][y], ty = xj[6][x][y];
      printf("%d:%d ", ty, tx);
      x -= tx, y -= ty;
      tx = xi[2][x][y], ty = xj[2][x][y];
      printf("%d:%d ", ty, tx);
      x -= tx, y -= ty;
      printf("%d:%d\n", y, x);
      continue;
    }
  }
  return 0;
}
