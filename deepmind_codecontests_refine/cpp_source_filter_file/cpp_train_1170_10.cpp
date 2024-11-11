#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
const long long maxn = 5e2 + 10, maxm = 1e5 + 10, lg = 23, mod = 1e9 + 7,
                inf = 1e18;
char c[maxn][maxn];
long long dp[maxn];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> c[i][j];
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      memset(dp, 69, sizeof(dp));
      dp[0] = 0;
      for (int j = 1; j <= m; j++) {
        if (c[i][j] == '.') dp[j] = min(dp[j], dp[j - 1] + x);
        if (c[i][j] == '.' && j >= 2 && c[i][j - 1] == '.')
          dp[j] = min(dp[j], dp[j - 2] + y);
        if (c[i][j] == '*') dp[j] = dp[j - 1];
      }
      ans += dp[m];
    }
    cout << ans << endl;
  }
  return 0;
}
