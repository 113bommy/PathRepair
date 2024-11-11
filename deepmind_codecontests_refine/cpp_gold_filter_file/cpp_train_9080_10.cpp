#include <bits/stdc++.h>
using namespace std;
int dp[3010][3010], ans, n, m;
string s, t;
int main() {
  cin >> s >> t;
  n = s.size(), m = t.size();
  s = " " + s;
  t = " " + t;
  for (int i = 1; i <= n; i++) dp[i][i] = 2 * (i > m || s[1] == t[i]);
  for (int len = 2; len <= n; len++) {
    for (int l = 1, r; l + len - 1 <= n; l++) {
      r = l + len - 1;
      if (l > m || s[len] == t[l])
        dp[l][r] = (dp[l][r] + dp[l + 1][r]) % 998244353;
      if (r > m || s[len] == t[r])
        dp[l][r] = (dp[l][r] + dp[l][r - 1]) % 998244353;
    }
  }
  for (int i = m; i <= n; i++) ans = (ans + dp[1][i]) % 998244353;
  cout << ans << endl;
  return 0;
}
