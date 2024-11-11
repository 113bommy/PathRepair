#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const long long llinf = LLONG_MAX;
const int inf = INT_MAX;
const int nmax = 1e3 + 5;
const int mod = 1e9 + 7;
using namespace std;
int a[2][nmax], dp[2][nmax][52][52], n, p, k, i, j, g1, g2, r, x;
int main() {
  cin >> n >> p >> k >> r;
  while (r--) {
    cin >> x;
    a[0][--x] = 1;
  }
  cin >> r;
  while (r--) {
    cin >> x;
    a[1][--x] = 1;
  }
  if (n <= (p / 2) * k) p = (n / k + 1) * 2;
  for (i = n - 1; i >= 0; i--)
    for (j = 0; j <= p; j++)
      for (g1 = 0; g1 <= k; g1++)
        for (g2 = 0; g2 <= k; g2++) {
          dp[i % 2][j][g1][g2] =
              ((g1 && a[0][i]) || (g2 && a[1][i])) +
              dp[(i + 1) % 2][j][max(g1 - 1, 0)][max(g2 - 1, 0)];
          if (j && a[0][i])
            dp[i % 2][j][g1][g2] =
                max(dp[i % 2][j][g1][g2],
                    1 + dp[(i + 1) % 2][j - 1][k - 1][max(g2 - 1, 0)]);
          if (j && a[1][i])
            dp[i % 2][j][g1][g2] =
                max(dp[i % 2][j][g1][g2],
                    1 + dp[(i + 1) % 2][j - 1][max(g1 - 1, 0)][k - 1]);
        }
  cout << dp[0][p][0][0] << endl;
  return 0;
}
