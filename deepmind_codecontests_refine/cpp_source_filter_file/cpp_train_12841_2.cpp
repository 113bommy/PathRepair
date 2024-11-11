#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int n, a[305][305], dp[600][300][300];
void solve() {
  int id[305][305];
  dp[0][0][0] = a[0][0];
  int dn = 2 * (n - 1);
  for (int d = 1; d <= dn; d++) {
    int m = min(d, dn - d), sx = max(0, d - dn / 2);
    for (int x = sx, i = 0; x < n; x++, i++) {
      int y = d - x;
      id[x][y] = i;
    }
    for (int i = 0; i <= m; i++) {
      for (int j = i; j <= m; j++) {
        int x1 = sx + i, y1 = d - x1, x2 = sx + j, y2 = d - x2;
        dp[d][i][j] = -1000;
        for (int f = 0; f <= 1; f++) {
          for (int g = 0; g <= 1; g++) {
            int x3 = f ? x1 : (x1 - 1), y3 = f ? (y1 - 1) : y1,
                x4 = g ? x2 : (x2 - 1), y4 = g ? (y2 - 1) : y2;
            if (x3 < 0 || x3 >= n || y3 < 0 || y3 >= n || x4 < 0 || x4 >= n ||
                y4 < 0 || y4 >= n) {
              continue;
            }
            int id1 = id[x3][y3], id2 = id[x4][y4];
            if (id1 > id2) swap(id1, id2);
            int sum = dp[d - 1][id1][id2] + a[x1][y1] +
                      (x1 == x2 && y1 == y2 ? 0 : a[x2][y2]);
            dp[d][i][j] = max(dp[d][i][j], sum);
          }
        }
      }
    }
  }
  cout << dp[dn][0][0] << endl;
}
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    solve();
  }
}
