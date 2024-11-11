#include <bits/stdc++.h>
using namespace std;
double dp[100][2];
int main(void) {
  int n;
  cin >> n;
  vector<double> p(n);
  for (int i = 0; i < (int)(n); i++) cin >> p[i];
  sort(p.rbegin(), p.rend());
  double ans = 0;
  for (int k = 0; k < (int)(n); k++) {
    memset(dp, 0, sizeof(dp));
    if (k) swap(p[0], p[k - 1]);
    swap(p[0], p[k]);
    dp[0][0] = p[0];
    dp[0][1] = 1 - p[0];
    for (int i = 1; i < n; i++) {
      double t = dp[i - 1][0] * (1 - p[i]) + dp[i - 1][1] * p[i];
      if (t >= dp[i - 1][0]) {
        dp[i][0] = t;
        dp[i][1] = dp[i - 1][1] * (1 - p[i]);
      } else {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
      }
    }
    ans = max(ans, dp[n - 1][0]);
  }
  sort(p.rbegin(), p.rend());
  printf("%.10f\n", max(ans, p[0]));
  return 0;
}
