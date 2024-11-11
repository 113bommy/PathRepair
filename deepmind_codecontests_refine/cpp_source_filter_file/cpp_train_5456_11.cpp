#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
double dp[2 * N][N];
double a[2 * N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) cin >> a[i];
  for (int i = 0; i < 2 * N; i++)
    for (int j = 0; j < N; j++) dp[i][j] = 1e4;
  dp[2 * n][n] = 0;
  for (int i = 2 * n - 1; i >= 0; i--) {
    for (int f = 0; f <= n; f++) {
      dp[i][f] = dp[i + 1][f] + (a[i] - ceil(a[i]));
      if (f < n && abs(dp[i][f]) > abs(dp[i + 1][f + 1] + (a[i] - floor(a[i]))))
        dp[i][f] = dp[i + 1][f + 1] + (a[i] - floor(a[i]));
    }
  }
  cout << (fixed) << setprecision(3) << dp[0][0] << "\n";
}
