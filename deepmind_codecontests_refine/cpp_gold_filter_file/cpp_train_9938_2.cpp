#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
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
const int N = 5e3 + 10;
int n, a, b, k;
int dp[N][N], s[N];
int main() {
  scanf("%d%d%d%d", &n, &a, &b, &k);
  dp[0][a] = 1;
  int ans = 0;
  for (int i = 0; i <= k; ++i) {
    for (int first = 1; first <= n; ++first) {
      int &r = dp[i][first];
      if (i) (r += dp[i][first - 1]) %= P;
      if (!r) continue;
      if (i == k) (ans += r) %= P;
      int w = abs(first - b);
      if (w == 1) continue;
      (dp[i + 1][max(first - w + 1, 0)] += r) %= P;
      (dp[i + 1][first] -= r) %= P;
      (dp[i + 1][first + 1] += r) %= P;
      (dp[i + 1][min(first + w, n + 1)] -= r) %= P;
    }
  }
  if (ans < 0) ans += P;
  printf("%d\n", ans);
}
