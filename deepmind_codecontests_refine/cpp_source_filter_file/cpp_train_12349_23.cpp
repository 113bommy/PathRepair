#include <bits/stdc++.h>
using namespace std;
int ff[55], ss[55];
long double p[55];
long double dp[55][5500];
int n, r;
bool check(long double ans) {
  for (int j = 1; j <= r; ++j) {
    if (n == 1 and j == r) {
      dp[n][r] =
          p[n] * (ff[n] <= j ? (long double)ff[n] : (long double)ff[n] + ans) +
          (1.0 - p[n]) *
              (ss[n] <= j ? (long double)ss[n] : (long double)ss[n] + ans);
    } else {
      dp[n][j] = min(
          ans,
          p[n] * (ff[n] <= j ? (long double)ff[n] : (long double)ff[n] + ans) +
              (1.0 - p[n]) *
                  (ss[n] <= j ? (long double)ss[n] : (long double)ss[n] + ans));
    }
  }
  for (int i = n - 1; i >= 1; --i) {
    for (int j = 1; j <= r; ++j) {
      long double a =
          p[i] * (ff[i] <= j ? (long double)ff[i] + dp[i + 1][j - ff[i]]
                             : (long double)ff[i] + ans) +
          (1.0 - p[i]) * (ss[i] <= j ? (long double)ss[i] + dp[i + 1][j - ss[i]]
                                     : (long double)ss[i] + ans);
      if (i == 1 and j == r) {
        dp[i][j] = a;
      } else
        dp[i][j] = min(ans, a);
    }
  }
  return dp[1][r] < ans;
}
int main() {
  cin >> n >> r;
  for (int i = 1; i <= n; ++i) {
    cin >> ff[i] >> ss[i] >> p[i];
    p[i] /= 100.0;
  }
  long double lo = 0, hi = 1e18, md;
  for (int i = 0; i < 180; ++i) {
    md = (lo + hi) / 2.0;
    if (check(md))
      hi = md;
    else
      lo = md;
  }
  cout << fixed << setprecision(10) << hi << endl;
}
