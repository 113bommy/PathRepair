#include <bits/stdc++.h>
using namespace std;
long long dp[2005][2005][2][2][2];
const int mod = 1e9 + 7;
string s;
string a, b;
long long d, m;
long long solve(long long pos, long long mo, bool tight, bool st, bool even) {
  if (pos == s.size()) {
    return (mo == 0);
  }
  if (dp[pos][mo][tight][st][even] != -1) return dp[pos][mo][tight][st][even];
  long long ret = 0;
  long long en = (tight ? (s[pos] - '0') : 9);
  if (st == 0) {
    ret = (ret + solve(pos + 1, mo, tight & (s[pos] == '0'), st, 0)) % mod;
    for (long long i = 1; i <= en; i++) {
      if (i != d)
        ret =
            (ret + solve(pos + 1, (mo * 10 + i) % m, tight & (i == en), 1, 1)) %
            mod;
    }
  } else {
    for (long long i = 0; i <= en; i++) {
      if (even && (i == d))
        ret = (ret +
               solve(pos + 1, (mo * 10 + i) % m, tight & (i == en), 1, !even)) %
              mod;
      else if ((!even) && (i != d))
        ret = (ret +
               solve(pos + 1, (mo * 10 + i) % m, tight & (i == en), 1, !even)) %
              mod;
    }
  }
  return dp[pos][mo][tight][st][even] = ret;
}
int main() {
  cin >> m >> d;
  cin >> a >> b;
  s = b;
  memset(dp, -1, sizeof dp);
  long long ans = solve(0, 0, 1, 0, 0);
  s = a;
  memset(dp, -1, sizeof dp);
  ans -= solve(0, 0, 1, 0, 0);
  ans += mod;
  ans %= mod;
  long long mo = 0;
  bool flg = 1;
  for (long long i = 0; i < a.size(); i++) {
    if (i % 2 and ((a[i] - '0') != d)) flg = 0;
    if (i % 2 == 0 and ((a[i] - '0') == d)) flg = 0;
    mo = ((mo * 10) + (a[i] - '0')) % m;
  }
  if (mo == 0 and flg) {
    ans = (ans + 1) % mod;
  }
  cout << ans;
}
