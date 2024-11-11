#include <bits/stdc++.h>
using namespace std;
int n, k;
long long dp[3000][3000];
int main() {
  cin >> n >> k;
  dp[0][1] = 1;
  for (int i = 1; i < k + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      for (int nw = j; nw < n + 1; nw += j)
        dp[i][nw] += dp[i - 1][j], dp[i][nw] %= 1000000007;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += dp[k][i], ans %= 1000000007;
  cout << ans << endl;
  return 0;
}
