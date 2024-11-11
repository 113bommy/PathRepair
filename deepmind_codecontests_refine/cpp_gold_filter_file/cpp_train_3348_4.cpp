#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, P2 = 998244353, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 1e6 + 10;
int n, q, a[N];
int dp[N][22], f[22];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 0; i <= 20; ++i) f[i] = n + 1;
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j <= 20; ++j) dp[i][j] = n + 1;
    for (int j = 0; j <= 20; ++j)
      if (a[i] >> j & 1) {
        dp[i][j] = f[j];
        for (int k = 0; k <= 20; ++k)
          if (dp[f[j]][k]) dp[i][k] = min(dp[i][k], dp[f[j]][k]);
      }
    for (int j = 0; j <= 20; ++j)
      if (a[i] >> j & 1) f[j] = i;
  }
  while (q--) {
    int first, second, flag = 0;
    scanf("%d%d", &first, &second);
    for (int j = 0; j <= 20; ++j)
      if ((a[second] >> j & 1) && dp[first][j] <= second) flag = 1;
    puts(flag ? "Shi" : "Fou");
  }
}
