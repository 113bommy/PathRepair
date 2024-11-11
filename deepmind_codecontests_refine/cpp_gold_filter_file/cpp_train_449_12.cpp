#include <bits/stdc++.h>
using namespace std;
const long long INF = 3000000000000LL;
int main() {
  cout << fixed;
  cout.precision(9);
  int n;
  cin >> n;
  long long c[n];
  int t[n];
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> c[i];
    t[i]++;
  }
  long long dp[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    dp[0][i] = INF;
  }
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int m = 0; m < n; m++)
    for (int s = 1; s <= n; s++) {
      int s1 = s - t[m];
      if (s1 < 0) s1 = 0;
      dp[m + 1][s] = min(dp[m][s], c[m] + dp[m][s1]);
    }
  cout << dp[n][n] << endl;
  return 0;
}
