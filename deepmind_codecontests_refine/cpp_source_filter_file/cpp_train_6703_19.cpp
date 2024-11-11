#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
const int inf = 1e9 + 7;
int n, t, ans;
int num[maxn][maxn][2], f[maxn][maxn][2];
void out(int x, int y, int k) {
  if (x == 1 && y == 1) {
    printf(k ? "D" : "R");
    return;
  }
  if (x == 1)
    out(x, y - 1, 0);
  else if (y == 1)
    out(x - 1, y, 1);
  else if (f[x][y][t] == f[x][y - 1][t] + num[x][y][t])
    out(x, y - 1, 0);
  else
    out(x - 1, y, 1);
  if (x != n || y != n) printf(k ? "D" : "R");
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      scanf("%d", &x);
      if (!x) {
        num[i][j][0] = num[i][j][1] = 1;
        t = i;
      } else {
        while (!(x % 2)) ++num[i][j][0], x /= 2;
        while (!(x % 5)) ++num[i][j][0], x /= 5;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    f[0][i][0] = f[i][0][0] = f[0][i][1] = f[i][0][1] = inf;
  f[1][1][0] = num[1][1][0], f[1][1][1] = num[1][1][1];
  for (int k = 0; k <= 1; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = i == 1 ? 2 : 1; j <= n; j++) {
        f[i][j][k] = min(f[i][j - 1][k], f[i - 1][j][k]) + num[i][j][k];
      }
    }
  }
  ans = min(f[n][n][0], f[n][n][1]);
  if (t && ans > 1) {
    printf("1\n");
    for (int i = 1; i < t; i++) printf("D");
    for (int i = 1; i < n; i++) printf("R");
    for (int i = t; i < n; i++) printf("D");
  } else {
    printf("%d\n", ans);
    t = !(f[n][n][0] < f[n][n][1]);
    out(n, n, 0);
  }
  return 0;
}
