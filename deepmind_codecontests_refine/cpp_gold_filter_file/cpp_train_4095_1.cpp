#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int dp[maxn][30];
char str[maxn];
char s[maxn];
bool flag[27][27];
int main() {
  int i, j, k;
  while (scanf("%s", str) != -1) {
    fill(flag[0], flag[27], 0);
    fill(dp[0], dp[maxn], maxn);
    scanf("%d", &k);
    while (k--) {
      scanf("%s", s);
      flag[s[0] - 'a'][s[1] - 'a'] = 1;
      flag[s[1] - 'a'][s[0] - 'a'] = 1;
    }
    dp[0][str[0] - 'a'] = 0;
    dp[0][26] = 1;
    int n = strlen(str);
    int ans = maxn;
    for (i = 1; i < n; i++) {
      for (k = 0; k < 27; k++)
        if (dp[i - 1][k] != maxn) {
          int j = str[i] - 'a';
          if (flag[k][j]) {
            dp[i][k] = min(dp[i][k], dp[i - 1][k] + 1);
          } else {
            dp[i][j] = min(dp[i][j], dp[i - 1][k]);
            dp[i][k] = min(dp[i][k], dp[i - 1][k] + 1);
          }
        }
    }
    for (i = 0; i < 27; i++) ans = min(ans, dp[n - 1][i]);
    printf("%d\n", ans);
  }
  return 0;
}
