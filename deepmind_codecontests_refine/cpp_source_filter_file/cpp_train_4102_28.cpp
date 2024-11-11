#include <bits/stdc++.h>
const int MAXN = 1e6 + 20, M = 998244353;
int read() {
  int x = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') (c == '-') ? f = 1, c = getchar() : c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (48 ^ c), c = getchar();
  return (f) ? -x : x;
}
int main() {
  int n = read();
  int cnt_1 = 0, cnt_2 = 0;
  for (int i = 0; i < n; ++i) {
    int a = read();
    if (a == 1)
      ++cnt_1;
    else
      ++cnt_2;
  }
  int dp[MAXN];
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= cnt_1; ++i)
    dp[i] = (1ll * dp[i - 2] * (i - 1) % M + dp[i - 1]) % M;
  int ans = 1;
  for (int i = n; i > cnt_1; --i) ans = 1ll * ans * i % M;
  printf("%lld", 1ll * dp[cnt_1] * ans % M);
}
