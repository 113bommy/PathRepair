#include <bits/stdc++.h>
using namespace std;
const int N = 1009, INF = 0x3f3f3f3f;
int c[N][N][2], n, ans, f[N][N][2], sx, sy;
bool g[N][N], p;
void print(int x, int y, int t) {
  if (x == 1 && y == 1) {
    putchar(t ? 'D' : 'R');
    return;
  }
  if (f[x][y][p] == f[x][y - 1][p] + c[x][y][p])
    print(x, y - 1, 0);
  else
    print(x - 1, y, 1);
  if (~t) putchar(t ? 'D' : 'R');
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int a;
      scanf("%d", &a);
      if (!a)
        sx = i, sy = j;
      else {
        int ba = a;
        while (ba % 2 == 0) c[i][j][0]++, ba /= 2;
        ba = a;
        while (ba % 5 == 0) c[i][j][1]++, ba /= 5;
      }
    }
  for (int i = 1; i <= n; i++) c[0][i][0] = c[0][i][1] = -1;
  for (int i = 1; i <= n; i++) c[i][0][0] = c[i][0][1] = -1;
  memset(f, INF, sizeof f);
  f[1][1][0] = c[1][1][0];
  f[1][1][1] = c[1][1][1];
  for (int i = 1; i <= n; i++)
    for (int j = i == 1 ? 2 : 1; j <= n; j++) {
      f[i][j][0] = min(f[i - 1][j][0], f[i][j - 1][0]) + c[i][j][0];
      f[i][j][1] = min(f[i - 1][j][1], f[i][j - 1][1]) + c[i][j][1];
    }
  ans = min(f[n][n][1], f[n][n][0]);
  if (ans > 1 && sx && sy) {
    puts("1");
    for (int i = 1; i < sx; i++) putchar('D');
    for (int j = 1; j < sy; j++) putchar('R');
    for (int j = sy; j <= n; j++) putchar('R');
    for (int j = sx; j <= n; j++) putchar('D');
  } else {
    printf("%d\n", ans);
    if (p = (f[n][n][0] > f[n][n][1]))
      print(n, n, -1);
    else
      print(n, n, -1);
  }
  return 0;
}
