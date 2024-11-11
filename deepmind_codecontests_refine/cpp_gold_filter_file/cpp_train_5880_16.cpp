#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000;
int n, k;
double dp[1003][103][103];
int perm[103];
int main() {
  scanf("%d %d", &n, &k);
  k = min(k, 1000);
  for (int r = (1); r < (k + 1); ++r) {
    for (int i = (0); i < (n); ++i)
      for (int j = (i + 1); j < (n); ++j) {
        dp[r][i][j] +=
            (i * (i + 1) + (j - i - 1) * (j - i) + (n - 1 - j) * (n - j)) *
            dp[r - 1][i][j] / 2;
        for (int s = (i); s < (i + j); ++s) {
          dp[r][i][j] +=
              (min(i, s - i) - max(0, s - j + 1) + 1) * dp[r - 1][s - i][j];
        }
        for (int s = (i + j + 1); s < (j + n); ++s) {
          dp[r][i][j] +=
              (min(j, s - j) - max(i + 1, s - n + 1) + 1) * dp[r - 1][i][s - j];
        }
        for (int s = (j); s < (i + n); ++s) {
          dp[r][i][j] += (min(i, s - j) - max(0, s - n + 1) + 1) *
                         (1 - dp[r - 1][s - j][s - i]);
        }
        dp[r][i][j] *= (double)2 / n / (n + 1);
      }
  }
  double res = 0;
  for (int i = (0); i < (n); ++i) scanf("%d", &perm[i]);
  for (int i = (0); i < (n); ++i)
    for (int j = (i + 1); j < (n); ++j)
      if (perm[i] < perm[j])
        res += dp[k][i][j];
      else
        res += 1 - dp[k][i][j];
  cout.precision(9);
  cout << fixed << res << endl;
  return 0;
}
