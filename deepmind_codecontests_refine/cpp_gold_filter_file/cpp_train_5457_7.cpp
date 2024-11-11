#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
char s[maxn][maxn];
int dp[maxn][maxn];
int ans;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '1') {
        int c = j;
        while (s[i][j] == '1') {
          dp[c][j]++;
          j++;
        }
      }
    }
  }
  for (int i = m; i >= 1; i--) {
    for (int j = 1; j <= i; j++) dp[j][i] = dp[j][i] + dp[j - 1][i];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= i; j++) ans = max(ans, dp[j][i] * (i - j + 1));
  }
  cout << ans << endl;
}
