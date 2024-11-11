#include <bits/stdc++.h>
using namespace std;
const long long sz = 1e5 + 5;
string s[2];
long long a[2][105];
long long dp[105][105];
long long rec(long long m, long long n) {
  if (m < 0 || n < 0) return 0;
  if (dp[m][n] != -1)
    return dp[m][n];
  else {
    long long l1, l2, l3, l4, l5, l6, l7, l8;
    l2 = rec(m - 1, n);
    l3 = rec(m - 1, n - 1);
    l4 = rec(m - 1, n - 2);
    l1 = rec(m, n - 1);
    l7 = rec(m - 2, n - 1);
    l8 = rec(m - 2, n - 2);
    if ((m - n == 1 && !a[0][m] && !a[0][m - 1] && !a[1][n])) ++l7;
    if ((n - m == 1 && !a[1][n] && !a[1][n - 1] && !a[0][m])) ++l2;
    if (m == n && !a[0][m] && !a[0][m - 1] && !a[1][n]) ++l7;
    if (m == n && !a[0][m] && !a[1][n] && !a[1][n - 1]) ++l4;
    long long ans = max(l1, max(l2, max(l3, max(l4, max(l7, l8)))));
    return dp[m][n] = ans;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  cin >> s[0];
  cin >> s[1];
  for (long long k = 0; k < 2; ++k)
    for (long long i = 0; i < s[k].length(); ++i) a[k][i] = (s[k][i] == 'X');
  long long l = s[0].length();
  cout << rec(l - 1, l - 1);
}
