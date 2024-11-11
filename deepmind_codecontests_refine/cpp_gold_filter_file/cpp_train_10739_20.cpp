#include <bits/stdc++.h>
using namespace std;
template <class T>
T read1() {
  T t = 0;
  bool vis = 0;
  char k;
  do (k = getchar()) == '-' && (vis = 1);
  while ('0' > k || k > '9');
  while ('0' <= k && k <= '9')
    t = (t << 3) + (t << 1) + (k ^ '0'), k = getchar();
  return vis ? -t : t;
}
int dp[505][505], s, m, w[505][505], f[505][505], a[505];
int main() {
  s = read1<int>(), m = read1<int>();
  dp[0][0] = dp[s + 1][s + 1] = 1;
  for (int i = 1; i <= s; ++i)
    a[i] = read1<int>(), w[i][i] = i, dp[i][i] = 1, f[i][i] = 1;
  for (int i = 1; i < s; ++i)
    for (int j = i + 1; j <= s; ++j)
      w[i][j] = a[w[i][j - 1]] < a[j] ? w[i][j - 1] : j;
  for (int i = 1; i <= s + 1; ++i) f[i][i - 1] = dp[i][i - 1] = 1;
  for (int len = 2; len <= s; ++len)
    for (int i = 1, j; j = i + len - 1, i <= s - len + 1; ++i) {
      int n = w[i][j];
      f[i][j] = dp[i][j] = 1ll * dp[i][n - 1] * dp[n + 1][j] % 998244353;
      for (int k = i; k < j; ++k)
        dp[i][j] = (dp[i][j] + 1ll * f[i][k] * dp[k + 1][j]) % 998244353;
    }
  printf("%d", dp[1][s]);
  return 0;
}
