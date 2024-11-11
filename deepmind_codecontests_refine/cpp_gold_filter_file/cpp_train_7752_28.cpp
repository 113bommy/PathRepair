#include <bits/stdc++.h>
using namespace std;
int N, K, eps, Xi, Yi, X0, Y0;
double dist[111];
double prob[111];
double dp[111][111];
double p(int D, double R) {
  if (D <= R * R)
    return 1;
  else
    return exp(1 - D / R / R);
}
bool ok(double R) {
  for (int i = (0); i < (N); i++) prob[i] = p(dist[i], R);
  for (int i = (0); i < (111); i++)
    for (int j = (0); j < (111); j++) dp[i][j] = 0;
  dp[0][0] = 1;
  for (int i = (1); i <= (N); i++) {
    dp[i][0] = dp[i - 1][0] * (1 - prob[i - 1]);
    for (int j = (1); j <= (N); j++)
      dp[i][j] =
          dp[i - 1][j - 1] * prob[i - 1] + dp[i - 1][j] * (1. - prob[i - 1]);
  }
  double p_res = 0;
  for (int i = (K); i <= (N); i++) p_res += dp[N][i];
  return p_res * 1000 >= 1000 - eps;
}
void solve() {
  double R_lo = 0.0, R_hi = 1000000.0, R_mid;
  for (int i = (0); i < (200); i++) {
    R_mid = (R_lo + R_hi) / 2.;
    if (ok(R_mid)) {
      R_hi = R_mid;
    } else {
      R_lo = R_mid;
    }
  }
  printf("%.9f\n", R_mid);
}
int main() {
  cin >> N >> K >> eps >> X0 >> Y0;
  for (int i = (0); i < (N); i++) {
    cin >> Xi >> Yi;
    dist[i] = (X0 - Xi) * (X0 - Xi) + (Y0 - Yi) * (Y0 - Yi);
  }
  solve();
}
