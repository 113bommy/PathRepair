#include <bits/stdc++.h>
using namespace std;
long long dp[100100][2];
long long n;
long long a[100100];
string s[2][100100];
signed main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> s[0][i];
    s[1][i] = s[0][i];
    reverse(s[1][i].begin(), s[1][i].end());
  }
  memset(dp, 0x3f, sizeof(dp));
  long long init = dp[0][0];
  dp[0][0] = 0;
  dp[0][1] = a[0];
  for (long long i = 1; i < n; i++) {
    if (s[0][i - 1] < s[0][i]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
    if (s[1][i - 1] < s[0][i]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    if (s[0][i - 1] < s[1][i]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
    if (s[1][i - 1] < s[1][i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
  }
  if (dp[n - 1][0] == init || dp[n - 1][1] == init)
    cout << "-1\n";
  else
    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
  return 0;
}
