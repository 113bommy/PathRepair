#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int dp[N][N], cnt[N][N], num[N][N];
char c[N][N];
int n, m, ans;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> c[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (c[i][j] != c[i - 1][j])
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i - 1][j] + 1;
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
      if (c[i][j] != c[i][j - 1])
        cnt[i][j] = 1;
      else
        cnt[i][j] = cnt[i][j - 1] + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[i - dp[i][j]][j] >= dp[i][j]) {
        if (dp[i + dp[i][j]][j] == dp[i][j]) {
          int add = 1e9;
          for (int k = i - dp[i][j]; k <= i + dp[i][j]; k++)
            add = min(add, cnt[k][j]);
          ans += add;
        }
      }
    }
  }
  cout << ans << endl;
}
