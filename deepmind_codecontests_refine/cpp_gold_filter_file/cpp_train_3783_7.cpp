#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
const long long linf = 9000000000000000000LL;
const double finf = 1.0e18;
const double eps = 1.0e-8;
int m, n, a[505][505], s[505][505][2], ans;
bool done(int x, int y, int z) {
  return (1 <= x) && (x <= m) && (1 <= y) && (y <= n) && (x + z - 1 <= m) &&
         (y + z - 1 <= n);
}
int solve(int x, int y, int z) {
  int ret = 0;
  if (z == 3) {
    ret = s[x][y + 2][0] - s[x][y - 1][0] + s[x + 2][y + 2][0] -
          s[x + 2][y - 1][0] + a[x + 1][y + 2];
  } else if (z == 5) {
    ret = s[x][y + 4][0] - s[x][y - 1][0] + s[x + 2][y + 2][0] -
          s[x + 2][y - 1][0] + s[x + 4][y + 4][0] - s[x + 4][y - 1][0] +
          s[x + 3][y + 4][1] - s[x][y + 4][1] + a[x + 3][y];
  } else {
    ret = s[x][y + z - 1][0] - s[x][y - 1][0] + s[x + z - 1][y + z - 1][0] -
          s[x + z - 1][y - 1][0] + s[x + z - 2][y + z - 1][1] -
          s[x][y + z - 1][1] + s[x + z - 2][y][1] - s[x + 1][y][1] +
          a[x + 2][y + 1] + solve(x + 2, y + 2, z - 4);
  }
  ans = max(ans, ret);
  return ret;
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= m; i++) {
    s[i][0][0] = 0;
    for (int j = 1; j <= n; j++) {
      s[i][j][0] = s[i][j - 1][0] + a[i][j];
    }
  }
  for (int j = 1; j <= n; j++) {
    s[0][j][1] = 0;
    for (int i = 1; i <= m; i++) {
      s[i][j][1] = s[i - 1][j][1] + a[i][j];
    }
  }
  ans = -inf;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int k = min(m - i + 1, n - j + 1);
      if (!(k & 1)) k--;
      while (k >= 3) {
        if (done(i - 2, j - 2, k + 4)) break;
        solve(i, j, k);
        k -= 2;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
