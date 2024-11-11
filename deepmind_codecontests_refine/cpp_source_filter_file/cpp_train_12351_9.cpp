#include <bits/stdc++.h>
using namespace std;
const int N = 2010, mod = 998244353;
int inc(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
int dec(int x, int y) {
  x -= y;
  return x < 0 ? x + mod : x;
}
int mul(int x, int y) { return (long long)x * y % mod; }
int power(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1, x = mul(x, x))
    if (y & 1) ans = mul(ans, x);
  return ans;
}
int n, a, b, ans[N], dp[N], f[N][N], p, ip, pw[N], ipw[N];
int main() {
  scanf("%d%d%d", &n, &a, &b);
  p = mul(a, power(b, mod - 2));
  ip = mod - p + 1;
  pw[0] = ipw[0] = 1;
  for (int i = 1; i <= n; i++)
    pw[i] = mul(pw[i - 1], p), ipw[i] = mul(ipw[i - 1], ip);
  for (int i = 0; i <= n; i++)
    for (int j = f[i][0] = 1; j <= i; j++)
      f[i][j] = inc(mul(f[i - 1][j - 1], ipw[i - j]), mul(f[i - 1][j], pw[j]));
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      int res = inc(inc(ans[j], ans[i - j]), j * (j - 1) / 2 + j * (i - j)),
          K = mul(f[i][j], dp[j]);
      dp[i] = dec(dp[i], K);
      ans[i] = inc(ans[i], mul(K, res));
    }
    ans[i] = inc(ans[i], mul(dp[i], n * (n - 1) / 2));
    ans[i] = mul(ans[i], power(dec(1, dp[i]), mod - 2));
  }
  printf("%d\n", ans[n]);
  return 0;
}
