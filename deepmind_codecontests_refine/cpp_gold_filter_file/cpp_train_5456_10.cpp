#include <bits/stdc++.h>
using namespace std;
const int N = 4003;
double a[N], dp[N][N];
int main() {
  int n;
  scanf("%d", &n);
  n += n;
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &a[i]);
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = 1e18;
    }
  }
  dp[n][n / 2] = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n / 2; j >= 0; --j) {
      if (abs(dp[i + 1][j + 1] + ceil(a[i]) - a[i]) <
          abs(dp[i + 1][j] + floor(a[i]) - a[i])) {
        dp[i][j] = dp[i + 1][j + 1] + ceil(a[i]) - a[i];
      } else {
        dp[i][j] = dp[i + 1][j] + floor(a[i]) - a[i];
      }
    }
  }
  printf("%.3lf\n", abs(dp[0][0]));
}
