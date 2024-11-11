#include <bits/stdc++.h>
using namespace std;
double a[20][20];
double dp[1005][20];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) cin >> a[i][j];
  memset(dp, 0, sizeof(dp));
  dp[1][0] = 1;
  for (int i = 2; i < (1 << n); i++)
    for (int j = 0; j < n; j++)
      if ((i & (1 << j)) > 0) {
        for (int k = 0; k < n; k++)
          if (k != j && (i & (1 << k))) {
            dp[i][j] = max(dp[i][j], dp[i ^ (1 << j)][k] * a[k][j] +
                                         dp[i ^ (1 << k)][j] * a[j][k]);
          }
      }
  double MAX = 0;
  for (int i = 0; i < n; i++) {
    MAX = max(MAX, dp[(1 << n) - 1][i]);
  }
  printf("%.10f\n", MAX);
  return 0;
}
