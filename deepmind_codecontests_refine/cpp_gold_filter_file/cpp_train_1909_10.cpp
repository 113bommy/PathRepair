#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long const inf = 1e18, linf = 2e9, mod = 1e9 + 7;
int const mxn = 5e3 + 10;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
long long dp[mxn][mxn], ans;
string s, t;
int main() {
  cin >> s >> t;
  int ss = s.size(), ts = t.size();
  s = "#" + s, t = "#" + t;
  for (int i = 1; i <= ss; i++) {
    for (int j = 1; j <= ts; j++) {
      dp[i][j] += (dp[i - 1][j - 1] + 1) * (s[i] == t[j]) + dp[i][j - 1];
      dp[i][j] %= mod;
    }
  }
  for (int i = 1; i <= ss; i++) {
    ans += dp[i][ts];
    ans %= mod;
  }
  cout << ans;
}
