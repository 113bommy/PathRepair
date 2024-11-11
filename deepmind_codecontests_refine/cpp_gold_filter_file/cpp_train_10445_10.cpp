#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
int p[210];
int a[210];
double dp[210][210][410];
int main() {
  int n, l, k;
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0][0][k + 200] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int s = 0; s <= 400; s++) {
        if (dp[i][j][s] < eps) continue;
        dp[i + 1][j][s] += dp[i][j][s] * (100 - p[i]) / 100.0;
        dp[i + 1][j + 1][max(0, min(s + a[i], 400))] +=
            dp[i][j][s] * p[i] / 100.0;
      }
    }
  }
  double res = 0;
  for (int i = 200; i <= 400; i++)
    for (int j = l; j <= 200; j++) res += dp[n][j][i];
  printf("%.9lf", res);
}
