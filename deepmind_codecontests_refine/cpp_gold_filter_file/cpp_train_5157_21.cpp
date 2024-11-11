#include <bits/stdc++.h>
using namespace std;
int n;
int x[1005], y[1005];
int data[2020][2020];
int flag[2100][2100][4];
int minx, miny, maxx, maxy;
void saomiao() {
  int i, j;
  for (i = minx; i <= maxx; i++) {
    int num = 0;
    int y1;
    for (j = maxy; j >= miny; j--) {
      if (flag[i][j] && flag[i + 1][j]) num++;
      if (num == 1) y1 = j;
      if (num == 2) {
        for (int k = y1 - 1; k >= j; k--) data[i][k] = 1;
        num = 0;
      }
    }
  }
}
int jisuan() {
  int ans = 0;
  int i, j;
  int zx = x[1];
  int zy = y[1];
  for (i = 2; i <= n + 1; i++) {
    int nx = x[i];
    int ny = y[i];
    if (nx == zx) {
      if (ny > zy) {
        if (data[nx][ny] || data[nx][ny--]) ans++;
      } else {
        if (data[nx--][ny--] || data[nx--][ny]) ans++;
      }
    } else {
      if (nx > zx) {
        if (data[nx--][ny] || data[nx][ny]) ans++;
      } else {
        if (data[nx--][ny--] || data[nx][ny--]) ans++;
      }
    }
    zx = nx;
    zy = ny;
  }
  return ans;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    int i, j;
    minx = 999999;
    miny = 999999;
    maxx = -999999;
    maxy = -999999;
    memset(flag, 0, sizeof(flag));
    memset(data, 0, sizeof(data));
    int ux;
    int uy;
    for (i = 1; i <= n + 1; i++) {
      scanf("%d%d", &x[i], &y[i]);
    }
    printf("%d\n", (n - 4) / 2);
  }
  return 0;
}
