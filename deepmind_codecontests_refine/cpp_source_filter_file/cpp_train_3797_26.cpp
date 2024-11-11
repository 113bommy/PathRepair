#include <bits/stdc++.h>
const int N = 40 + 5;
const int INF = 0x3f3f3f3f;
char s1[N], s2[N], cast[N][3];
int n;
bool ok1[N][N][N], ok2[N][N][N];
int dp[N][N];
int main() {
  std::scanf("%s%s%d%*[ \n]", s1 + 1, s2 + 1, &n);
  int len1 = std::strlen(s1 + 1), len2 = std::strlen(s2 + 1);
  for (int i = 1; i <= n; i++)
    std::scanf("%c->%c%c%*[ \n]", &cast[i][0], &cast[i][1], &cast[i][2]);
  for (int i = 1; i <= len1; i++) ok1[i][i][s1[i] - 'a' + 1] = true;
  for (int _len = 1; _len <= len1; _len++)
    for (int l = 1; l + _len <= len1; l++) {
      int r = l + _len;
      for (int k = l; k < r; k++)
        for (int t = 1; t <= n; t++)
          ok1[l][r][cast[t][0] - 'a' + 1] |=
              (ok1[l][k][cast[t][1] - 'a' + 1] &&
               ok1[k + 1][r][cast[t][2] - 'a' + 1]);
    }
  for (int i = 1; i <= len2; i++) ok2[i][i][s2[i] - 'a' + 1] = true;
  for (int _len = 1; _len <= len2; _len++)
    for (int l = 1; l + _len <= len2; l++) {
      int r = l + _len;
      for (int k = l; k < r; k++)
        for (int t = 1; t <= n; t++)
          ok2[l][r][cast[t][0] - 'a' + 1] |=
              (ok2[l][k][cast[t][1] - 'a' + 1] &&
               ok2[k + 1][r][cast[t][2] - 'a' + 1]);
    }
  for (int i = 0; i <= len1; i++)
    for (int j = 0; j <= len2; j++) dp[i][j] = INF;
  dp[0][0] = 0;
  for (int i = 1; i <= len1; i++)
    for (int j = 1; j <= len2; j++) {
      for (int ti = 0; ti < i; ti++)
        for (int tj = 0; tj < j; tj++)
          for (int c = 1; c <= 26; c++)
            if (ok1[ti + 1][i][c] && ok2[tj + 1][j][c])
              dp[i][j] = std::min(dp[i][j], dp[ti][tj] + 1);
    }
  std::printf("%d\n", dp[len1][len2] == INF ? -1 : dp[len1][len2]);
  return 0;
}
