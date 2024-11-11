#include <bits/stdc++.h>
using namespace std;
ifstream fin("A.in");
ofstream fout("A.out");
long double dp[1002][1002], ans;
int n, m;
int main() {
  cin >> n >> m;
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= min(n, m); ++j) {
      if (dp[i][j] > 1e-12) {
        dp[i + 1][j + 1] += dp[i][j] * (m - j) / (n * m - i);
        dp[i + 1][j] += dp[i][j] * ((n - 1) * m - (i - j)) / (n * m - i);
      }
    }
  }
  for (int j = 1; j <= m; ++j) {
    ans += dp[n][j] * j * j / n;
  }
  cout << fixed << setprecision(7) << ans;
}
