#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3e3 + 5;
int dp[maxn][maxn], pre[maxn], a[maxn], b[maxn], tot, n, last[maxn];
void solve() {
  cin >> n;
  tot = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], last[i] = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] != a[i - 1]) b[++tot] = a[i];
  for (int i = 1; i <= tot; i++) a[i] = b[i];
  n = tot;
  for (int i = 1; i <= n; i++) pre[i] = last[a[i]], last[a[i]] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i <= j)
        dp[i][j] = inf;
      else
        dp[i][j] = 0;
  for (int i = 1; i <= n; i++) dp[i][i] = 0;
  for (int i = 1; i <= n - 1; i++)
    if (a[i] != a[i + 1])
      dp[i][i + 1] = 1;
    else
      dp[i][i + 1] = 0;
  for (int len = 3; len <= n; len++) {
    for (int i = 1, L, R; i + len - 1 <= n; i++) {
      L = i, R = i + len - 1;
      dp[L][R] = min(dp[L][R - 1] + 1, dp[L + 1][R] + 1);
      if (a[L] == a[R]) dp[L][R] = min(dp[L][R], dp[L + 1][R - 1] + 1);
      int cur = R;
      while (cur > L) {
        dp[L][R] = min(dp[L][R], dp[L][cur - 1] + dp[cur][R] + 1);
        if (a[L] == a[R])
          dp[L][R] = min(dp[L][cur - 1] + dp[cur + 1][R], dp[L][R]);
        cur = pre[i];
      }
    }
  }
  cout << dp[1][n] << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
