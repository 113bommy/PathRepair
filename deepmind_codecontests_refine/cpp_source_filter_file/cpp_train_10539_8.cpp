#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
const long long Mod = 998244353;
string s, t;
long long dp[3030][3030];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  cin >> s >> t;
  int n = s.length();
  int m = t.length();
  for (int i = 0; i < n; i++) {
    if (i >= m || s[0] == t[i]) dp[i][i] = 2ll;
  }
  int r;
  for (int len = 2; len <= n; len++) {
    for (int l = 0; l < n; l++) {
      r = l + len - 1;
      if (r >= n) break;
      if (l >= m || s[len - 1] == t[l])
        dp[l][r] = (dp[l][r] + dp[l + 1][r]) % Mod;
      if (r >= m || s[len - 1] == t[r])
        dp[l][r] = (dp[l][r] + dp[l][r - 1]) % Mod;
    }
  }
  long long ans = 0;
  for (int i = m - 1; i < n; i++) {
    (ans += 1ll * dp[0][i]) % Mod;
  }
  cout << ans << endl;
  return 0;
}
