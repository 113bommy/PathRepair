#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long r, s, p;
  cin >> r >> s >> p;
  double dp[101][101][101];
  for (long long i = r; i >= 0; i--) {
    for (long long j = s; j >= 0; j--) {
      for (long long k = p; k >= 0; k--) {
        long long tot = 0;
        if (i == r && j == s && k == p)
          dp[i][j][k] = 1;
        else {
          dp[i][j][k] = 0;
          if (j < s) {
            tot = i * (j + 1) + (j + 1) * k + k * i;
            if (tot)
              dp[i][j][k] += (((j + 1) * i * 1.0) / tot) * dp[i][j + 1][k];
          }
          if (k < p) {
            tot = i * j + j * (k + 1) + (k + 1) * i;
            if (tot)
              dp[i][j][k] += ((j * (k + 1) * 1.0) / tot) * dp[i][j][k + 1];
          }
          if (i < r) {
            tot = (i + 1) * j + j * k + k * (i + 1);
            if (tot)
              dp[i][j][k] += ((k * (i + 1) * 1.0) / tot) * dp[i + 1][j][k];
          }
        }
      }
    }
  }
  double res = 0;
  for (long long i = 1; i <= r; i++) res += dp[i][0][0];
  printf("%.9f ", res);
  res = 0;
  for (long long i = 1; i <= s; i++) res += dp[0][i][0];
  printf("%.9f ", res);
  res = 0;
  for (long long i = 1; i <= p; i++) res += dp[0][0][i];
  printf("%.9f\n", res);
}
