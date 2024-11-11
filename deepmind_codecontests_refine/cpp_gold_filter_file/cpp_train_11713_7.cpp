#include <bits/stdc++.h>
using namespace std;
const int inf = 0x20202020;
const long long mod = 1000000007;
const double eps = 1e-9;
const double pi = acos(-1);
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 100;
const int M = 1000;
double dp[N + 1][N * M + 5];
int n, m;
int a[N + 5];
int main() {
  scanf("%d %d", &n, &m);
  if (m == 1) {
    puts("1.000000000000000");
    return 0;
  }
  for (int i = (1), i_end_ = (n + 1); i < i_end_; ++i) scanf("%d", &a[i]);
  memset(dp, 0, sizeof dp);
  dp[0][0] = m - 1;
  for (int i = (1), i_end_ = (n + 1); i < i_end_; ++i) {
    double sum = 0;
    for (int j = (0), j_end_ = (n * m + 1); j < j_end_; ++j) {
      if (j - a[i] >= 0)
        dp[i][j] = (sum - dp[i - 1][j - a[i]]) / (m - 1);
      else
        dp[i][j] = sum / (m - 1);
      if (j - m >= 0) sum -= dp[i - 1][j - m];
      sum += dp[i - 1][j];
    }
  }
  double ans = 1;
  int tot = 0;
  for (int i = (1), i_end_ = (n + 1); i < i_end_; ++i) tot += a[i];
  for (int i = (0), i_end_ = (tot); i < i_end_; ++i) ans += dp[n][i];
  printf("%.15lf\n", ans);
  return 0;
}
