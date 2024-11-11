#include <bits/stdc++.h>
using namespace std;
int dp[41][41][41][41];
char a[41][41];
int s[41][41];
int z(int x1, int x2, int y1, int y2) {
  x1--, y1--;
  return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
}
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j] - '0';
    }
  }
  for (int lx = 1; lx <= n; lx++) {
    for (int x1 = 1; x1 + lx - 1 <= n; x1++) {
      int x2 = x1 + lx - 1;
      for (int y1 = 1; y1 <= m; y1++) {
        int l = y1 - 1;
        for (int y2 = y1; y2 <= m; y2++) {
          if (z(x1, x2, y2, y2)) l = y2;
          dp[x1][x2][y1][y2] = dp[x1][x2][y1][y2 - 1] + (y2 - l);
        }
      }
      for (int y1 = 1; y1 <= m; y1++) {
        for (int y2 = y1; y2 <= m; y2++) {
          dp[x1][x2][y1][y2] += dp[x1 + 1][x2][y1][y2] +
                                dp[x1][x2 - 1][y1][y2] -
                                dp[x1 + 1][x2 - 1][y1][y2];
        }
      }
    }
  }
  for (int i = 0; i < q; i++) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", dp[x1][x2][y1][y2]);
  }
}
