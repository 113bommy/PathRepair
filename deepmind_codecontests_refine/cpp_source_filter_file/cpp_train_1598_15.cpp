#include <bits/stdc++.h>
using namespace std;
int n, l, v;
int a[205];
double ans;
double p[205];
double dp[205][205][405];
int main() {
  cin >> n >> l >> v;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    p[i] /= 100;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0][v] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= 400; k++) {
        dp[i + 1][j][k] += (1 - p[i + 1]) * dp[i][j][k];
        if (min(k + a[i + 1], 400) > 0)
          dp[i + 1][j + 1][min(k + a[i + 1], 400)] += p[i + 1] * dp[i][j][k];
      }
    }
  }
  for (int i = v; i <= 400; i++) {
    for (int j = l; j <= n; j++) {
      ans += dp[n][j][i];
    }
  }
  cout << setprecision(6) << fixed << ans << '\n';
  return 0;
}
