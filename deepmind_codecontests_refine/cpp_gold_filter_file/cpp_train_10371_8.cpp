#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = 1000 * 1000 * 1000 + 21;
const long long int LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX_N = (1 << 7);
int n;
int lgn;
int pr[MAX_N][MAX_N];
long double dp[MAX_N][MAX_N];
long double dp_pr[MAX_N][MAX_N];
int main() {
  scanf("%d", &n);
  lgn = n;
  n = (1 << n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &pr[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dp[i][j] = 0;
      dp_pr[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) dp_pr[0][i] = 1;
  for (int sh = 1, lg = 1; sh < n; (sh <<= 1), ++lg) {
    for (int i = 0; i < n; i += (sh << 1)) {
      for (int j = i; j < i + sh; ++j) {
        for (int k = i + sh; k < i + (sh << 1); ++k) {
          if (lg != 1) {
            dp[lg][j] = max(dp[lg][j], dp[lg - 1][j] + dp[lg - 1][k] +
                                           dp_pr[lg - 1][j] * (1 << (lg - 2)) +
                                           dp_pr[lg - 1][k] * (1 << (lg - 2)));
            dp[lg][k] = max(dp[lg][k], dp[lg - 1][j] + dp[lg - 1][k] +
                                           dp_pr[lg - 1][j] * (1 << (lg - 2)) +
                                           dp_pr[lg - 1][k] * (1 << (lg - 2)));
          }
          dp_pr[lg][j] +=
              dp_pr[lg - 1][j] * dp_pr[lg - 1][k] * (pr[j][k] / 100.0);
          dp_pr[lg][k] +=
              dp_pr[lg - 1][j] * dp_pr[lg - 1][k] * (pr[k][j] / 100.0);
        }
      }
    }
  }
  long double ans = 0;
  for (int i = 0; i < n; ++i)
    ans = max(ans, dp[lgn][i] + (1 << (lgn - 1)) * dp_pr[lgn][i]);
  cout << fixed << setprecision(20);
  cout << ans << "\n";
  return 0;
}
