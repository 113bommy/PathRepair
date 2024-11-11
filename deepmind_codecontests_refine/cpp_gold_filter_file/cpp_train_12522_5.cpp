#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
int dp[N][N];
int main() {
  int n, m;
  string a, b;
  cin >> n >> m >> a >> b;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max({dp[i][j], dp[i - 1][j] - 1, dp[i][j - 1] - 1});
      if (a[i - 1] == b[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
}
