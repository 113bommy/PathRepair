#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int n, p;
long long dp[N + 1][N + 1];
long long c[N + 1][N + 1];
int main() {
  for (int i = 1; i <= N; ++i) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  dp[0][0] = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p);
    for (int j = i; j; --j)
      for (int k = 50; k >= p; --k) dp[j][k] += dp[j - 1][k - p];
  }
  scanf("%d", &p);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= 50; ++j) dp[i][j] += dp[i][j - 1];
  double res = 0;
  for (int i = 1; i <= n; ++i) {
    res += dp[i][p] * 1.0 / c[n][i];
  }
  printf("%.9lf\n", res);
  return 0;
}
