#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
using namespace std;
const double eps = 1E-15;
const double Exp = 2.718281828459045;
const double Pi = 3.1415926535897932;
const int NMAX = 5000 + 5;
const int MMAX = 100000 + 5;
const int INF = 1000000000;
const int BASE = 1000000007;
template <typename T>
inline T abs(const T a) {
  if (a < 0) return -a;
  return a;
}
template <typename T>
inline T sqr(const T& a) {
  return a * a;
}
int main() {
  ios::sync_with_stdio(false);
  int n, T;
  int i, j;
  int t[NMAX];
  int p[NMAX];
  static float sum[NMAX][NMAX] = {0};
  static float dp[NMAX][NMAX] = {0};
  cin >> n >> T;
  for (i = 1; i <= n; i++) {
    cin >> p[i] >> t[i];
  }
  p[0] = 1;
  t[0] = 0;
  dp[0][0] = 1;
  sum[0][0] = 1;
  for (i = 0; i <= n; i++) {
    for (j = i; j <= T; j++) {
      if (i > 0) {
        if (j >= t[i])
          dp[i][j] = dp[i - 1][j - t[i]] * pow((1 - p[i] / 100.0), t[i] - 1) +
                     (sum[i - 1][j - 1] -
                      sum[i - 1][j - t[i]] * pow(1 - p[i] / 100.0, t[i] - 1)) *
                         p[i] / 100.0;
        else
          dp[i][j] = (sum[i - 1][j - 1]) * p[i] / 100.0;
      }
      if (j > 0) sum[i][j] = sum[i][j - 1] * (1 - p[i + 1] / 100.0) + dp[i][j];
      if (dp[i][j] < eps) dp[i][j] = 0;
      if (sum[i][j] < eps) sum[i][j] = 0;
    }
  }
  t[n + 1] = INF;
  p[n + 1] = 0;
  double res = 0;
  double cur;
  for (i = 1; i <= n; i++) {
    cur = 1;
    for (j = T; j >= max(1, T - t[i + 1] + 1); j--) {
      res += i * dp[i][j] * cur;
      cur *= (1 - p[i + 1] / 100.0);
    }
  }
  cout << setprecision(8) << fixed << res << endl;
  return 0;
}
