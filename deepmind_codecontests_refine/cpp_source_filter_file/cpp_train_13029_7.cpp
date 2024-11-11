#include <bits/stdc++.h>
using namespace std;
long long power(long long first, long long second) {
  long long ret = 1;
  for (; second; second >>= 1) {
    if (second & 1) ret = ret * first % 998244353;
    first = first * first % 998244353;
  }
  return ret;
}
long long frac(long long first, long long second) {
  return first * power(second, 998244353 - 2) % 998244353;
}
int n, m;
int a[20005], b[20005], goodw, badw;
long long dp[3005][3005];
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    if (a[i])
      goodw += b[i];
    else
      badw += b[i];
  }
  dp[0][0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= min(badw, i); j++)
      if (dp[i][j]) {
        const int gt = i - j, bt = j;
        (dp[i + 1][j] += dp[i][j] * frac(goodw + gt, goodw + badw + gt - bt)) %=
            998244353;
        (dp[i + 1][j + 1] +=
         dp[i][j] * frac(badw - bt, goodw + badw + gt - bt)) %= 998244353;
      }
  }
  long long gbase = 0, bbase = 0;
  for (int i = 0; i <= m; i++) {
    (gbase += dp[m][m - i] * i) %= 998244353;
    (bbase += dp[m][i] * i) %= 998244353;
  }
  (gbase *= power(goodw, 998244353 - 2)) %= 998244353;
  (bbase *= power(badw, 998244353 - 2)) %= 998244353;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      printf("%lld\n", b[i] * (1 + gbase) % 998244353);
    } else {
      printf("%lld\n", b[i] * (1 + 998244353 - bbase) % 998244353);
    }
  }
}
