#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 2;
const int maxm = 10 + 2;
const int ABC = 26;
int n;
int len[maxm];
char str[maxn][maxm];
int change(char ch) { return ch - 'a'; }
int dp[ABC][ABC];
void DP() {
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < ABC; i++) dp[i][i] = 0;
  for (int i = 1; i <= n; i++) {
    int l = change(str[i][1]), r = change(str[i][len[i]]);
    for (int j = 0; j < ABC; j++)
      if (~dp[j][l]) dp[j][r] = max(dp[j][r], dp[j][l] + len[i]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str[i] + 1);
    len[i] = strlen(str[i] + 1);
  }
  DP();
  int ans = 0;
  for (int i = 0; i < ABC; i++) ans = max(ans, dp[i][i]);
  printf("%d", ans);
  return 0;
}
