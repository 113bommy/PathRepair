#include <bits/stdc++.h>
using namespace std;
long long dp[4005][4005];
long long lasta[4005][26];
long long lastb[4005][26];
signed main() {
  long long INSERT, DELETE, REPLACE, SWAP;
  string a, b;
  cin >> INSERT >> DELETE >> REPLACE >> SWAP;
  cin >> a;
  cin >> b;
  long long n = a.length();
  long long m = b.length();
  memset(lasta, -1, sizeof(lasta));
  memset(lastb, -1, sizeof(lastb));
  a = '*' + a;
  b = '*' + b;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < 26; j++) {
      lasta[i][j] = lasta[i - 1][j];
    }
    lasta[i][a[i] - 'a'] = i;
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = 0; j < 26; j++) {
      lastb[i][j] = lastb[i - 1][j];
    }
    lastb[i][b[i] - 'a'] = i;
  }
  dp[0][0] = 0;
  for (long long i = 1; i <= n; i++) dp[i][0] = DELETE * i;
  for (long long i = 1; i <= m; i++) dp[0][i] = INSERT * i;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1];
        continue;
      }
      dp[i][j] = min(dp[i][j - 1] + INSERT, dp[i - 1][j] + DELETE);
      dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + REPLACE);
      long long la = lasta[i][b[j] - 'a'];
      long long lb = lastb[j][a[i] - 'a'];
      if (la != -1 && lb != -1)
        dp[i][j] = min(dp[i][j], dp[la][lb] + (i - la - 1) * DELETE +
                                     (j - lb - 1) * INSERT + SWAP);
    }
  }
  cout << dp[n][m];
}
