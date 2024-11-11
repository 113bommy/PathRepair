#include <bits/stdc++.h>
using namespace std;
long long m, d, MOD = 1e9 + 7, ans = 0;
string a, b;
long long dp[2001][2001][2];
long long ncount(string& s) {
  for (int i = 0; i <= (int)s.size(); i++)
    for (int y = 0; y < m; y++) dp[i][y][0] = dp[i][y][1] = 0;
  dp[0][0][1] = 1;
  for (int i = 0; i < (int)s.size(); i++) {
    for (int y = 0; y < m; y++) {
      for (int k = 0; k < 2; k++) {
        for (int p = 0; p <= (k ? int(s[i] - '0') : 9); p++) {
          if ((i & 1) && p != d) continue;
          if (!(i & 1) && p == d) continue;
          if (!i && !p) continue;
          int ni = i + 1;
          int ny = (y * 10 + p) % m;
          int nk = k && (p == int(s[i] - '0'));
          dp[ni][ny][nk] = (dp[ni][ny][nk] + dp[i][y][k]) % MOD;
        }
      }
    }
  }
  return (dp[(int)s.size()][0][0] + dp[(int)s.size()][0][1]) % MOD;
}
int check(string& s) {
  long long balance = 0;
  for (size_t i = 0; i < s.size(); i++) {
    if (i % 2 == 1 && s[i] - '0' != d) return 0;
    if (i % 2 == 0 && s[i] - '0' == d) return 0;
    balance *= 10;
    balance += s[i] - '0';
    balance %= m;
  }
  if (!balance)
    return 1;
  else
    return 0;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> m >> d >> a >> b;
  ans = ncount(b) - ncount(a) + check(a);
  if (ans < 0) ans += 2 * MOD;
  cout << ans % MOD;
  return 0;
}
