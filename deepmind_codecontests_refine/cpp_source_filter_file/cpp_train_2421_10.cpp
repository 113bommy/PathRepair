#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
  return x;
}
int n, m, q;
const int N = 1e5 + 7;
int dp[N][2];
char s[5][N];
int b[5], r[5];
int solve1() {
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  dp[0][1] = 0;
  for (int i = 1; i <= n; ++i) {
    int vb = (s[1][i] == 'B') + (s[2][i] == 'B');
    int vr = 2 - vb;
    dp[i][1] = min(dp[i - 1][1] + vb, dp[i - 1][0] + vb + m);
    dp[i][0] = min(dp[i - 1][0] + vr, dp[i - 1][1] + vr + m);
    if (i == 1) dp[i][1] += b[3], dp[i][0] += r[3];
    if (i == n) dp[i][1] += b[4], dp[i][0] += r[4];
  }
  return min(dp[n][1], dp[n][0]);
}
int solve2() {
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  dp[0][1] = 0;
  for (int i = 1; i <= m; ++i) {
    int vb = (s[3][i] == 'B') + (s[4][i] == 'B');
    int vr = 2 - vb;
    dp[i][1] = min(dp[i - 1][1] + vb, dp[i - 1][0] + vb + n);
    dp[i][0] = min(dp[i - 1][0] + vr, dp[i - 1][1] + vr + n);
    if (i == 1) dp[i][1] += b[1], dp[i][0] += r[1];
    if (i == m) dp[i][1] += b[2], dp[i][0] += r[2];
  }
  return min(dp[m][1], dp[m][0]);
}
int main() {
  n = read(), m = read();
  read();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i] + 1);
    int len = strlen(s[i] + 1);
    for (int j = 1; j <= len; ++j) {
      if (s[i][j] == 'B')
        b[i]++;
      else
        r[i]++;
    }
  }
  int ans = min(solve1(), solve2());
  printf("%d\n", ans);
  return 0;
}
