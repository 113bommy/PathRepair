#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const long long Mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= Mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % Mod;
    a = a * a % Mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int n, a, b;
long long dp[1005][1005];
int main() {
  scanf("%d", &n);
  for (a = 1; a <= n; a++) dp[a][a] = (a + 1) / 2;
  dp[1][0] = 1;
  for (a = 2; a <= n; a++) {
    for (b = a - 1; b >= 1; b--) {
      dp[a][b] = (b == a - 1) ? 1 : 0;
      dp[a][b] += (dp[a][b + 1] + dp[a - 1][b - 1]);
      dp[a][b] = dp[a][b] % Mod;
    }
    dp[a][0] = dp[a][1];
  }
  printf("%I64d\n", dp[n][1]);
  return 0;
}
