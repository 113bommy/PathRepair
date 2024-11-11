#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
const int MOD = 998244353, MAX_N = 3000;
int dp[MAX_N][MAX_N + 1];
int main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  ;
  string s, t;
  cin >> s >> t;
  for (int l_pos = 0; l_pos < MAX_N; l_pos++) dp[l_pos][0] = 1;
  for (int len = 1; len <= s.length(); len++) {
    for (int l_pos = 0; l_pos + len <= s.length(); l_pos++) {
      if (l_pos >= t.length() || s[len - 1] == t[l_pos])
        dp[l_pos][len] += dp[l_pos + 1][len - 1];
      int r_pos = l_pos + len - 1;
      if (r_pos >= t.length() || s[len - 1] == t[r_pos])
        dp[l_pos][len] += dp[l_pos][len - 1];
      dp[l_pos][len] %= MOD;
    }
  }
  int ans = 0;
  for (int len = t.length(); len <= s.length(); len++)
    ans = (ans + dp[0][len]) % MOD;
  cout << ans;
}
