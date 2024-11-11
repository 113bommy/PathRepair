#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int N = 55;
long long fpow(long long bs, long long idx) {
  long long res = 1;
  while (idx) {
    if (idx & 1) (res *= bs) %= MOD;
    (bs *= bs) %= MOD;
    idx >>= 1;
  }
  return res;
}
int n, L[N], R[N], t[N];
long long dp[N][N << 2], sum = 1;
inline long long C(long long x, long long y) {
  if (y > x) return 0ll;
  if (y == 0 || x == y) return 1ll;
  long long res = 1, tmp = 1;
  for (long long i = x; i >= x - y + 1; i--) (res *= i) %= MOD;
  for (long long i = 1; i <= y; i++) (tmp *= i) %= MOD;
  return res * fpow(tmp, MOD - 2) % MOD;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &L[i], &R[i]);
    (sum *= (R[i] - L[i] + 1)) %= MOD;
    t[++t[0]] = L[i], t[++t[0]] = R[i] + 1;
  }
  sort(t + 1, t + t[0] + 1);
  t[0] = unique(t + 1, t + t[0] + 1) - (t + 1);
  for (int i = 1; i <= n; i++) {
    L[i] = lower_bound(t + 1, t + t[0] + 1, L[i]) - t;
    R[i] = lower_bound(t + 1, t + t[0] + 1, R[i] + 1) - t;
  }
  for (int j = 1; j <= t[0]; j++) dp[0][j] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = L[i]; j < R[i]; j++) {
      for (int k = 1; k <= i; k++) {
        if (L[i - k + 1] > j || R[i - k + 1] <= j) break;
        (dp[i][j] += dp[i - k][j + 1] * C(t[j + 1] - t[j] + k - 1, k) % MOD) %=
            MOD;
      }
    }
    for (int j = t[0] - 1; j >= 1; j--) (dp[i][j] += dp[i][j + 1]) %= MOD;
  }
  printf("%lld\n", dp[n][1] * fpow(sum, MOD - 2) % MOD);
  return 0;
}
