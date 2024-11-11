#include <bits/stdc++.h>
using namespace std;
const int maxn = 410;
int T, len1, len2;
int nex[maxn][31];
int dp[maxn][maxn];
char s[maxn], t[maxn];
void ready(int n) {
  for (int i = 1; i <= 26; i++) nex[n][i] = n + 1;
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= 26; j++) nex[i - 1][j] = nex[i][j];
    nex[i - 1][s[i] - 'a' + 1] = i;
  }
}
bool check(int n) {
  int m = len2 - n;
  dp[0][0] = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      if (!i && !j) continue;
      dp[i][j] = len1 + 1;
      if (i && dp[i - 1][j] < len1)
        dp[i][j] = min(dp[i][j], nex[dp[i - 1][j]][t[i] - 'a' + 1]);
      if (j && dp[i][j - 1] < len1)
        dp[i][j] = min(dp[i][j], nex[dp[i][j - 1]][t[len1 + j] - 'a' + 1]);
    }
  return dp[n][m] <= len1;
}
void solve() {
  scanf("%s%s", s + 1, t + 1);
  len1 = strlen(s + 1);
  len2 = strlen(t + 1);
  ready(len1);
  for (int i = 1; i <= len2; i++)
    if (check(i)) {
      printf("YES\n");
      return;
    }
  printf("NO\n");
  return;
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
