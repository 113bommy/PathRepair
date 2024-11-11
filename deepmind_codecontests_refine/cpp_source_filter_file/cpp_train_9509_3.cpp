#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const int mod = 1000000007;
long long len, n, dp[maxn][2], num;
char s[maxn], t[maxn];
int read();
int Search() {
  int ret = 0, flg = 0;
  for (int i = 0; i < len; ++i) {
    flg = 0;
    for (int j = 0; j < len; ++j) {
      if (s[(i + j) % len] != s[j]) {
        flg = 1;
        break;
      }
    }
    if (!flg) ret++;
  }
  return ret;
}
int main() {
  scanf("%s%s%I64d", s, t, &n);
  len = strlen(s);
  int flg = 0;
  for (int i = 0; i < len; ++i)
    if (s[i] != t[i]) {
      flg = 1;
      break;
    }
  if (flg)
    dp[0][1] = 1;
  else
    dp[0][0] = 1;
  num = Search();
  for (int i = 1; i <= n; ++i) {
    dp[i][1] =
        dp[i - 1][0] * (len - num) % mod + (len - num - 1) * dp[i - 1][1] % mod;
    dp[i][0] = dp[i - 1][1] * num % mod + dp[i - 1][0] * (num - 1) % mod;
    dp[i][1] %= mod;
    dp[i][1] += mod;
    dp[i][1] %= mod;
    dp[i][0] %= mod;
    dp[i][0] += mod;
    dp[i][0] %= mod;
  }
  printf("%I64d\n", dp[n][0]);
  return 0;
}
int read() {
  int ret = 0, sig = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') sig = 1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    ret = (ret << 3) + (ret << 1) + ch - 48;
    ch = getchar();
  }
  if (sig) return -ret;
  return ret;
}
