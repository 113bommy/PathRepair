#include <bits/stdc++.h>
using namespace std;
int n, k, e;
int x[103], y[103];
long double dp[103][103];
long double p[103];
int main() {
  cin >> n >> k >> e;
  int a, b;
  cin >> a >> b;
  int i, j;
  for (i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i] -= a;
    y[i] -= b;
  }
  long double l = 0.000000;
  long double r = 20000.000000;
  long double re;
  while (r - l > 0.000000001) {
    re = (l + r) / 2.000;
    for (i = 0; i < n; i++)
      if ((long double)x[i] * x[i] + (long double)y[i] * y[i] > re * re)
        p[i] =
            pow(2.7182818284590452353602874713527,
                1.000 - ((long double)x[i] * x[i] + (long double)y[i] * y[i]) /
                            (re * re));
      else
        p[i] = 1.000;
    dp[0][0] = 1.000;
    for (i = 1; i <= n; i++)
      for (j = 0; j <= i; j++) {
        dp[i][j] = dp[i - 1][j] * (1 - p[i - 1]);
        if (j != 0) dp[i][j] += dp[i - 1][j - 1] * p[i - 1];
      }
    long double res = 0.0000;
    for (i = k; i <= n; i++) res += dp[n][i];
    if (1 - res > (long double)e / 1000.000)
      l = re;
    else
      r = re;
  }
  cout << setprecision(20) << r << endl;
  return 0;
}
