#include <bits/stdc++.h>
const int N = 2e3 + 10;
const int inf = 0x3f3f3f3f;
const double eps = 1e-7;
const int mod = 1e9 + 7;
const double p = acos(-1.0);
using namespace std;
long long dp[N][N];
char s[100010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  int ps = inf, cc = 0, ans = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '(')
      cc++;
    else
      cc--;
    ps = min(ps, cc);
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n - m; i++)
    for (int j = 0; j <= i; j++) {
      if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
      dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
    }
  for (int i = 0; i <= n - m; i++)
    for (int j = 0; j <= i; j++) {
      if (j + ps >= 0 && j + cc <= n - m - i)
        ans = (ans + dp[i][j] * dp[n - m - i][j + cc] % mod) % mod;
    }
  cout << ans << endl;
  return 0;
}
