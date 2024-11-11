#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 1061109567;
const int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
double dp[205][205][405], p[205];
int a[205];
int main() {
  int n, l, tmp;
  cin >> n >> l >> tmp;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    p[i] /= 100;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0][200 + tmp] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= 400; k++) {
        if (a[i + 1] == -1) {
          if (k > 0) dp[i + 1][j + 1][k - 1] += dp[i][j][k] * p[i + 1];
          dp[i + 1][j][k] += dp[i][j][k] * (1 - p[i + 1]);
        } else {
          int val = min(400, k + a[i + 1]);
          if (k > 0) dp[i + 1][j + 1][val] += dp[i][j][k] * p[i + 1];
          dp[i + 1][j][k] += dp[i][j][k] * (1 - p[i + 1]);
        }
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 200; j <= 400; j++) {
      ans += dp[n][i][j];
    }
  }
  printf("%.8f\n", ans);
  return 0;
}
