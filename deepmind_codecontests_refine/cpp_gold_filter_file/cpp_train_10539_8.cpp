#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s, T;
  cin >> s >> T;
  string t = T;
  for (long long i = 0;
       i < ((long long)((s).size()) - (long long)((T).size())) + 1; ++i) {
    t += '#';
  }
  long long n = (long long)((s).size());
  s = "0" + s;
  t = "0" + t;
  vector<vector<long long> > dp(n + 2, vector<long long>(n + 2, 0));
  for (long long i = 1; i <= n + 1; ++i) {
    dp[i][0] = 1;
  }
  for (long long j = 1; j <= n; ++j) {
    for (long long i = 1; i + j - 1 <= n; ++i) {
      if (t[i] == '#') {
        dp[i][j] += dp[i + 1][j - 1];
      } else if (s[j] == t[i]) {
        dp[i][j] += dp[i + 1][j - 1];
      }
      dp[i][j] %= 998244353;
      if (t[i + j - 1] == '#') {
        dp[i][j] += dp[i][j - 1];
      } else if (s[j] == t[i + j - 1]) {
        dp[i][j] += dp[i][j - 1];
      }
      dp[i][j] %= 998244353;
    }
  }
  long long ans = 0;
  for (long long i = (long long)((T).size()); i <= n; ++i) {
    ans += dp[1][i];
    ans %= 998244353;
  }
  cout << ans << "\n";
  return 0;
}
