#include <bits/stdc++.h>
using namespace std;
const int maxd = 1000000007, N = 100000;
const double pi = acos(-1.0);
int n, pre[30], suf[30], len;
long long dp[100100][30];
char s[100100];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
void init(int now) {
  scanf("%s", s + 1);
  len = strlen(s + 1);
  int i, j;
  memset(pre, 0, sizeof(pre));
  memset(suf, 0, sizeof(suf));
  for (j = 0; j < 26; j++) {
    int cnt = 0, maxlen = 0;
    for (i = 1; i <= len; i++)
      if (s[i] - 'a' == j) {
        cnt++;
        maxlen = max(maxlen, cnt);
      } else
        cnt = 0;
    dp[now][j] = maxlen;
    for (i = 1; i <= len; i++)
      if (s[i] - 'a' == j)
        pre[j]++;
      else
        break;
    for (i = len; i >= 1; i--)
      if (s[i] - 'a' == j)
        suf[j]++;
      else
        break;
  }
}
int main() {
  n = read();
  init(1);
  int i, j;
  for (i = 2; i <= n; i++) {
    init(i);
    for (j = 0; j < 26; j++) {
      if (dp[i - 1][j]) {
        if (pre[j] == len)
          dp[i][j] =
              max(dp[i][j], 1ll * len * (dp[i - 1][j] + 1) + dp[i - 1][j]);
        else
          dp[i][j] = max(dp[i][j], 1ll * (pre[j] + suf[j] + 1));
      }
    }
  }
  long long ans = 0;
  for (i = 0; i < n; i++) ans = max(ans, dp[n][i]);
  printf("%lld", ans);
  return 0;
}
