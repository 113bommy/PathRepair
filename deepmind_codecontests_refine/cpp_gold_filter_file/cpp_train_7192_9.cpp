#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int dp[2][205][105];
int n, m, a[maxn], nex[maxn], now;
int trans[205][2];
char s[maxn];
int main() {
  cin >> n;
  cin >> (s + 1);
  m = strlen(s + 1);
  for (int i = 1; i <= m; i++) {
    a[i] = (s[i] == '(') ? 0 : 1;
  }
  nex[0] = -1;
  for (int i = 1; i <= m; i++) {
    now = nex[i - 1];
    while (~now && a[now + 1] != a[i]) now = nex[now];
    nex[i] = now + 1;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      if (a[i + 1] == j) {
        trans[i][j] = i + 1;
      } else if (i > 0) {
        trans[i][j] = trans[nex[i]][j];
      }
    }
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < 2 * n; i++) {
    int cur = (i & 1);
    memset(dp[cur ^ 1], 0, sizeof(dp[cur ^ 1]));
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= n; k++) {
        if (j == m) {
          dp[cur ^ 1][m][k + 1] += dp[cur][m][k];
          if (k > 0) dp[cur ^ 1][m][k - 1] += dp[cur][m][k];
          dp[cur ^ 1][m][k + 1] %= mod;
          if (k > 0) dp[cur ^ 1][m][k - 1] %= mod;
          continue;
        }
        now = trans[j][0];
        dp[cur ^ 1][now][k + 1] += dp[cur][j][k];
        dp[cur ^ 1][now][k + 1] %= mod;
        now = trans[j][1];
        if (k > 0) {
          dp[cur ^ 1][now][k - 1] += dp[cur][j][k];
          dp[cur ^ 1][now][k - 1] %= mod;
        }
      }
    }
  }
  cout << dp[0][m][0] << endl;
  return 0;
}
