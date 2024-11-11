#include <bits/stdc++.h>
using namespace std;
const int maxn = 500;
int dp[maxn][maxn];
int a[maxn];
int solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i <= 2 * n; i++) dp[0][i] = 0;
  dp[1][1] = abs(1 - a[1]);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= 2 * n; j++) {
      if (j == a[i]) {
        dp[i][j] = dp[i - 1][j - 1];
        continue;
      }
      for (int k = 1; k < j; k++) {
        if (dp[i - 1][j - k] == -1) continue;
        int m_pos = 0;
        if (a[i] >= j)
          m_pos = j;
        else if (a[i] <= j - k)
          m_pos = j - k + 1;
        else
          m_pos = a[i];
        if (j - 1 >= 1) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + abs(m_pos - a[i]));
      }
    }
  int res = 0x3f3f3f3f;
  for (int i = n; i <= 2 * n; i++) res = min(dp[n][i], res);
  return res;
}
int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    cout << solve() << endl;
  }
  return 0;
}
