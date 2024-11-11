#include <bits/stdc++.h>
using namespace std;
const long long maxx = 2505;
string s;
long long n, dp[maxx][maxx], len;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  n = s.length() / 2 + 1;
  len = s.length();
  for (long long i = 0; i < n; i++) dp[i][i] = (s[2 * i] - '0');
  for (long long k = 1; k <= n - 1; k++) {
    for (long long i = 0; i + k < n; i++) {
      long long j = i + k, f = 1;
      long long cnt = 0, ja = i * 2 + 1;
      while (cnt < k && s[ja] != '+')
        f *= dp[(ja - 1) / 2][(ja - 1) / 2], ja += 2, cnt++;
      f *= dp[(ja - 1) / 2][(ja - 1) / 2];
      if (cnt == k)
        dp[i][j] = f;
      else
        dp[i][j] = f + dp[i + cnt + 1][j];
    }
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i; j < n; j++) {
      long long l = i, r = j, g = dp[i][j], ja;
      ja = i * 2 - 1;
      while (ja > 0 && s[ja] == '*')
        g *= dp[(ja - 1) / 2][(ja - 1) / 2], ja -= 2, l--;
      ja = j * 2 + 1;
      while (ja <= n * 2 - 3 && s[ja] == '*')
        g *= dp[(ja + 1) / 2][(ja + 1) / 2], ja += 2, r++;
      if (l > 0) g += dp[0][l - 1];
      if (r < n) g += dp[r + 1][n];
      ans = max(ans, g);
    }
  }
  cout << ans << endl;
  return 0;
}
