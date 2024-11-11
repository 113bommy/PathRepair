#include <bits/stdc++.h>
using namespace std;
long long n, t0, m;
vector<vector<double>> a;
vector<vector<double>> wr;
vector<vector<double>> dp;
int main() {
  scanf("%lld", &n);
  m = pow(2, n);
  a = vector<vector<double>>(m + 5, vector<double>(m + 5, 0));
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < m; j++) {
      scanf("%d", &t0);
      a[i][j] = 1.0 * t0 / 100.0;
    }
  }
  dp = vector<vector<double>>(n + 5, vector<double>(m + 5, 0));
  wr = vector<vector<double>>(n + 5, vector<double>(m + 5, 0));
  for (long long i = 0; i < m; i++) {
    wr[0][i] = 1.0;
  }
  for (long long round = 1; round <= n; round++) {
    vector<vector<pair<double, double>>> next =
        vector<vector<pair<double, double>>>(m + 5);
    for (long long game = 0; game < pow(2, n - round); game++) {
      for (long long x = game * pow(2, round);
           x < game * pow(2, round) + pow(2, round - 1); x++) {
        double maxDp = 0;
        double currentEp = 0;
        for (long long y = game * pow(2, round) + pow(2, round - 1);
             y < game * pow(2, round) + 2 * pow(2, round - 1); y++) {
          wr[round][x] += wr[round - 1][x] * wr[round - 1][y] * a[x][y];
          maxDp = max(maxDp, dp[round - 1][y]);
        }
        currentEp = wr[round][x] * pow(2, round - 1);
        dp[round][x] = maxDp + dp[round - 1][x] + currentEp;
      }
      for (long long y = game * pow(2, round) + pow(2, round - 1);
           y < game * pow(2, round) + 2 * pow(2, round - 1); y++) {
        double maxDp = 0;
        double currentEp = 0;
        for (long long x = game * pow(2, round);
             x < game * pow(2, round) + pow(2, round - 1); x++) {
          wr[round][y] += wr[round - 1][y] * wr[round - 1][x] * a[y][x];
          maxDp = max(maxDp, dp[round - 1][x]);
        }
        currentEp = wr[round][y] * pow(2, round - 1);
        dp[round][y] = maxDp + dp[round - 1][y] + currentEp;
      }
    }
  }
  double ans = 0;
  for (long long i = 0; i < n; i++) {
    ans = max(ans, dp[n][i]);
  }
  printf("%.10f\n", ans);
}
