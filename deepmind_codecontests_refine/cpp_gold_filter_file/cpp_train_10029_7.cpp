#include <bits/stdc++.h>
int i, j, k, n, m, p[2001], a[2001], x[1002001][26], y[2001][26],
    dp[2000][2002], dp2[2000][2002];
char t[1002001], s[2001];
int main() {
  for (i = 0; i < 2000; i++)
    for (j = 0; j < 2002; j++) dp[i][j] = 1e9;
  scanf("%d", &n);
  p[0] = 0;
  for (i = 0; i < n; i++) {
    scanf("%s", t + p[i]);
    for (p[i + 1] = p[i]; t[p[i + 1]]; p[i + 1]++)
      ;
    p[i + 1]++;
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) scanf("%d", a + i), a[i]--;
  scanf("%s", s);
  for (i = 0; i < n; i++) {
    for (j = 0; j < 26; j++) x[p[i + 1] - 1][j] = 1e9;
    for (j = p[i + 1] - 2; j >= p[i]; j--) {
      memcpy(x[j], x[j + 1], sizeof(x[j]));
      x[j][t[j] - 'a'] = j + 1;
    }
  }
  for (i = 0; i < 26; i++) y[m - 1][i] = 1e9;
  for (i = m - 2; i >= 0; i--) {
    for (j = 0; j < 26; j++) {
      if (x[p[a[i + 1]]][j] != 1e9)
        y[i][j] = i + 1;
      else
        y[i][j] = y[i + 1][j];
    }
  }
  dp[0][0] = p[a[dp2[0][0] = 0]];
  if (x[p[a[0]]][s[0] - 'a'] != 1e9)
    dp[0][1] = x[p[a[0]]][s[0] - 'a'], dp2[0][1] = 0;
  else if (y[0][s[0] - 'a'] != 1e9)
    dp[0][1] = x[p[a[y[0][s[0] - 'a']]]][s[0] - 'a'],
    dp2[0][1] = y[0][s[0] - 'a'];
  for (i = 1; s[i]; i++) {
    dp[i][0] = p[a[dp2[i][0] = 0]];
    for (j = 1; dp[i - 1][j] != 1e9; j++) {
      dp[i][j] = dp[i - 1][j], dp2[i][j] = dp2[i - 1][j];
      if (x[dp[i - 1][j - 1]][s[i] - 'a'] != 1e9) {
        if (dp2[i - 1][j - 1] < dp2[i][j] ||
            dp2[i - 1][j - 1] == dp2[i][j] &&
                x[dp[i - 1][j - 1]][s[i] - 'a'] < dp[i][j])
          dp[i][j] = x[dp[i - 1][j - 1]][s[i] - 'a'],
          dp2[i][j] = dp2[i - 1][j - 1];
      } else if (y[dp2[i - 1][j - 1]][s[i] - 'a'] != 1e9) {
        if (y[dp2[i - 1][j - 1]][s[i] - 'a'] < dp2[i][j] ||
            y[dp2[i - 1][j - 1]][s[i] - 'a'] == dp2[i][j] &&
                x[p[a[y[dp2[i - 1][j - 1]][s[i] - 'a']]]][s[i] - 'a'] <
                    dp[i][j])
          dp[i][j] = x[p[a[y[dp2[i - 1][j - 1]][s[i] - 'a']]]][s[i] - 'a'],
          dp2[i][j] = y[dp2[i - 1][j - 1]][s[i] - 'a'];
      }
    }
    if (x[dp[i - 1][j - 1]][s[i] - 'a'] != 1e9)
      dp[i][j] = x[dp[i - 1][j - 1]][s[i] - 'a'], dp2[i][j] = dp2[i - 1][j - 1];
    else if (y[dp2[i - 1][j - 1]][s[i] - 'a'] != 1e9)
      dp[i][j] = x[p[a[y[dp2[i - 1][j - 1]][s[i] - 'a']]]][s[i] - 'a'],
      dp2[i][j] = y[dp2[i - 1][j - 1]][s[i] - 'a'];
  }
  for (k = 1; dp[i - 1][k] != 1e9; k++)
    ;
  printf("%d\n", k - 1);
  return 0;
}
