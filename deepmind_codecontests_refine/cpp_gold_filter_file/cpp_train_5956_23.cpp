#include <bits/stdc++.h>
using namespace std;
const int P = 998244353, INF = 0x3f3f3f3f;
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
const int N = 2222, M = 2020;
int n, k, a[N], b[N], dp[N][N * 2];
void add(int &a, long long b) { a = (a + b) % P; }
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", b + i), a[i] = b[i];
  rotate(b + 1, b + n, b + 1 + n);
  dp[0][M] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = -i; j <= i; ++j) {
      int &r = dp[i - 1][j + M];
      if (!r) continue;
      if (a[i] == b[i])
        add(dp[i][j + M], (long long)k * r);
      else {
        add(dp[i][j + M], (long long)(k - 2) * r);
        add(dp[i][j + M + 1], r);
        add(dp[i][j + M - 1], r);
      }
    }
  int ans = 0;
  for (int i = 1; i <= n; ++i) add(ans, dp[n][i + M]);
  printf("%d\n", ans);
}
