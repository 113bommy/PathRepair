#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m;
double dp[2111][2111];
bool x[2111], y[2111];
int main() {
  int t, a, b, z, ca = 1;
  scanf("%d%d", &(n), &(m));
  int r = 0, c = 0;
  for (int i = (int)(1); i <= (int)(m); ++i) {
    scanf("%d%d", &(a), &(b));
    if (!x[a]) x[a] = 1, r++;
    if (!y[b]) y[b] = 1, c++;
  }
  dp[n][n] = 0.0;
  for (int i = n - 1; i >= 1; --i) dp[n][i] = 1.0 * n / (n - i) + dp[n][i + 1];
  for (int i = n - 1; i >= 1; --i) dp[i][n] = 1.0 * n / (n - i) + dp[i + 1][n];
  for (int i = n - 1; i >= 1; --i)
    for (int j = n - 1; j >= 1; --j) {
      dp[i][j] = 1.0 * (n * n) / (n * n - i * j) +
                 (dp[i + 1][j] * (n - i) * j + dp[i][j + 1] * i * (n - j) +
                  dp[i + 1][j + 1] * (n - i) * (n - j)) /
                     (n * n - i * j);
    }
  printf("%.7lf\n", dp[r][c]);
  return 0;
}
