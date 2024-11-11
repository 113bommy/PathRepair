#include <bits/stdc++.h>
using namespace std;
int i, j, x;
long long int n, k, ans = 0;
long long int last[27], dp[105][105];
string s;
int main() {
  cin >> n >> k >> s;
  dp[0][0] = 1;
  for (i = 0; i <= n; ++i) {
    x = s[i] - 'a';
    dp[i][0] = 1;
    for (j = 0; j <= i; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
      if (last[x]) dp[i][j] -= dp[last[x] - 1][j - 1];
    }
    last[x] = i;
  }
  for (i = n; i >= 0; --i) {
    if (k > dp[n][i]) {
      k -= dp[n][i];
      ans += dp[n][i] * (n - i);
    } else {
      ans += k * (n - i);
      cout << ans << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
