#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long x) { return x <= 1 ? 1 : inv(P % x) * (P - P / x) % P; }
long long dp[2][311][311];
int a[311], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int t;
    scanf("%d", &t);
    a[i] = 1;
    int mx = sqrt(t + 0.5);
    for (int j = 2; j <= mx; ++j)
      if (t % j == 0) {
        int c = 0;
        while (t % j == 0) t /= j, c ^= 1;
        if (c) a[i] *= j;
      }
    a[i] *= t;
  }
  sort(a + 1, a + 1 + n);
  dp[0][0][0] = 1;
  int cnt = 0, cur = 0;
  for (int i = 1; i <= n; ++i) {
    cur ^= 1;
    memset(dp[cur], 0, sizeof dp[cur]);
    for (int j = 0; j <= i - 1; ++j)
      for (int k = min(cnt, j); k >= 0; --k) {
        (dp[cur][j + 1][k + 1] += dp[cur ^ 1][j][k] * (2 * cnt - k)) %= P;
        if (j) (dp[cur][j - 1][k] += dp[cur ^ 1][j][k] * (j - k)) %= P;
        (dp[cur][j][k] += dp[cur ^ 1][j][k] * (i - 2 * cnt + 2 * k - j)) %= P;
      }
    ++cnt;
    if (a[i + 1] != a[i]) {
      for (int j = 0; j <= i - 1; ++j)
        for (int k = min(cnt, j); k >= 1; --k) {
          (dp[cur][j][0] += dp[cur][j][k]) %= P;
          dp[cur][j][k] = 0;
        }
      cnt = 0;
    }
  }
  cout << dp[cur][0][0] << endl;
}
