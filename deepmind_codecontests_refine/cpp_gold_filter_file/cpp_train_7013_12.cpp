#include <bits/stdc++.h>
const double eps = 1e-10;
using namespace std;
int n, a, b, c, d, i, j, k, m;
double f[123456];
vector<int> gr[123456];
long long dp[185][185][185];
long long F[123456], g[123456], diameter;
long long sms;
int P;
double pasx;
int over;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> g[i];
    sms += g[i];
  }
  cin >> P;
  long double pas = 0.0;
  if (sms <= P) {
    cout << n << endl;
    return 0;
  }
  f[0] = 1;
  for (int i = 1; i <= 60; i++) f[i] = f[i - 1] * i;
  for (over = 1; over <= n; over++) {
    for (i = 0; i < 70; i++) {
      for (j = 0; j < 60; j++) {
        for (k = 0; k < 60; k++) {
          dp[i][j][k] = 0;
        }
      }
    }
    dp[0][0][0] = 1;
    for (i = 1; i <= n; i++) {
      for (j = 0; j < i + 1; j++) {
        for (k = 0; k < 60; k++) {
          if (dp[i - 1][j][k]) {
            dp[i][j][k] += dp[i - 1][j][k];
            if (i != over) {
              dp[i][j + 1][k + g[i]] += dp[i - 1][j][k];
            }
          }
        }
      }
    }
    for (i = 0; i < n + 1; i++) {
      for (j = 0; j < P + 1; j++) {
        if (j + g[over] > P) {
          pasx += dp[n][i][j] / f[n] * f[i] * f[n - i - 1] * i;
        }
      }
    }
  }
  printf("%.10f", pasx);
  return 0;
}
