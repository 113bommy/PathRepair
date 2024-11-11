#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void solve() {
  string s, t;
  cin >> s;
  cin >> t;
  long long n = (long long)s.length();
  long long m = (long long)t.length();
  long long tpoint = 0;
  for (long long i = 0; i < n && tpoint < m; i++)
    if (s[i] == t[tpoint]) tpoint++;
  if (tpoint == m) {
    cout << "YES\n";
    return;
  }
  long long ok = false;
  for (long long split = 0; split < (m - 1); split++) {
    string s1 = "", s2 = "";
    for (long long i = 0; i <= split; i++) s1 += t[i];
    for (long long i = split + 1; i < m; i++) s2 += t[i];
    long long l1 = (split + 1), l2 = (m - split - 1);
    vector<vector<long long>> dp(n, vector<long long>(l1 + 1, -1));
    if (s[0] == s1[0]) {
      dp[0][1] = 0;
    }
    if (s[0] == s2[0]) {
      dp[0][0] = 1;
    } else {
      dp[0][0] = 0;
    }
    for (long long i = 1; i < n; i++) {
      for (long long j = 0; j <= min(i + 1, l1); j++) {
        dp[i][j] = dp[i - 1][j];
        if (dp[i - 1][j] == l2) continue;
        if (dp[i - 1][j] != -1 && s2[dp[i - 1][j]] == s[i])
          dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j]);
        if (j > 0 && dp[i - 1][j - 1] != -1 && s1[j - 1] == s[i])
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
    }
    ok |= dp[n - 1][l1] == l2;
  }
  if (ok)
    cout << "YES\n";
  else
    cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
