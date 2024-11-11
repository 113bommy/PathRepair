#include <bits/stdc++.h>
using namespace std;
const long long MAX1 = 2e3 + 300, MOD = 1e9 + 7;
long long n, k, dp[MAX1][MAX1], par[MAX1][MAX1];
string s[MAX1], t[10] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                         "1101011", "1101111", "1010010", "1111111", "1111011"};
long long super(string s1, string s2) {
  long long jav = 0;
  for (int i = 0; i < 7; ++i) {
    if (s1[i] == s2[i]) continue;
    if (s1[i] == '1') return 9;
    ++jav;
  }
  return jav + 10;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> s[i];
  for (int i = 0; i < MAX1; ++i) {
    for (int j = 0; j < MAX1; ++j) dp[i][j] = -1;
  }
  for (int i = 0; i < k; ++i) dp[n + 1][0] = -1;
  dp[n + 1][0] = 0;
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j <= k; ++j) {
      for (int l = 0; l < 10; ++l) {
        long long x = super(s[i], t[l]) - 10;
        if (x == -1) continue;
        if (x > j || dp[i + 1][j - x] == -1) continue;
        dp[i][j] = l;
        par[i][j] = j - x;
      }
    }
  }
  long long x = 1, y = k;
  if (dp[n][k] == -1) {
    cout << -1;
    return 0;
  }
  string ans = "";
  while (x <= n) {
    ans += char('0' + dp[x][y]);
    y = par[x][y];
    ++x;
  }
  cout << ans << endl;
  return 0;
}
