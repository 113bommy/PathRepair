#include <bits/stdc++.h>
using namespace std;
char s[210];
int n, K, p, dp[210][210][210], g[210];
struct mat {
  int a[310][310];
} r, ans;
mat mul(mat& x, mat& y) {
  mat ret;
  memset(&ret, 0, sizeof(ret));
  for (int i = 0; i <= p; i++)
    for (int j = i; j <= p; j++)
      for (int k = i; k <= j; k++)
        (ret.a[i][j] += x.a[i][k] * y.a[k][j] % 10007) %= 10007;
  return ret;
}
void ksm(int y) {
  while (y) {
    if (y & 1) ans = mul(ans, r);
    r = mul(r, r), y >>= 1;
  }
}
int main() {
  scanf("%s%d", s + 1, &K);
  n = strlen(s + 1);
  dp[1][n][0] = 1;
  for (int l = n; l; l--) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      for (int k = 0; k <= n - l; k++) {
        if (s[i] == s[j]) {
          if (l <= 2)
            (g[k] += dp[i][j][k]) %= 10007;
          else
            (dp[i + 1][j - 1][k] += dp[i][j][k]) %= 10007;
        } else {
          (dp[i + 1][j][k + 1] += dp[i][j][k]) %= 10007;
          (dp[i][j - 1][k + 1] += dp[i][j][k]) %= 10007;
        }
      }
    }
  }
  p = n + (n + 1) / 2;
  ans.a[0][1] = 1, ans.a[0][n] = g[0], r.a[p][p] = 26;
  for (int i = 1; i < n; i++) {
    r.a[i][i] = 24, r.a[i][p - (n - i + 1) / 2] = g[i];
    if (i < n - 1) r.a[i][i + 1] = 1;
  }
  for (int i = n; i < p; i++) r.a[i][i + 1] = 1, r.a[i][i] = 25;
  if ((n + K) & 1) {
    ksm(n + K + 1 >> 1);
    int fin = ans.a[0][p];
    memset(&r, 0, sizeof(r)), memset(&ans, 0, sizeof(ans)),
        memset(g, 0, sizeof(g));
    for (int i = 1; i < n; i++)
      if (s[i] == s[i + 1])
        for (int k = 0; k < n; k++) (g[k] += dp[i][i + 1][k]) %= 10007;
    ans.a[0][1] = 1, ans.a[0][n] = g[0];
    for (int i = 1; i < n; i++) {
      r.a[i][i] = 24, r.a[i][p - (n - i + 1) / 2] = g[i];
      if (i < n - 1) r.a[i][i + 1] = 1;
    }
    for (int i = n; i < p; i++) r.a[i][i + 1] = 1, r.a[i][i] = 25;
    ksm(n + K + 1 >> 1);
    printf("%d\n", (fin + 10007 - ans.a[0][p]) % 10007);
  } else {
    ksm(n + K >> 1);
    printf("%d\n", ans.a[0][p]);
  }
  return 0;
}
