#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000;
int in[maxn];
int dp[maxn][maxn];
int main() {
  int tot;
  cin >> tot;
  while (tot--) {
    int n, k;
    memset(dp, 0, sizeof(dp));
    cin >> n >> k;
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) cin >> in[i];
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        dp[i][j] = dp[i - 1][j];
        if (in[i] == i - j) dp[i][j]++;
        if (j != 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        if (dp[i][j] >= k) ans = min(ans, j);
      }
    }
    if (ans == 0x3f3f3f3f)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}
