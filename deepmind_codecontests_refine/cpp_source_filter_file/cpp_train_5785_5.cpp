#include <bits/stdc++.h>
using namespace std;
long long int Pow(long long int a, long long int b, long long int md,
                  long long int ans = 1) {
  for (; b; b >>= 1, a = a * a % md)
    if (b & 1) ans = ans * a % md;
  return ans % md;
}
const long long int MAXK = 2e3 + 10;
const long long int MAXN = 1e5 + 10;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
const long long int LOG = 22;
long long int dp[MAXK][LOG], inv[MAXN], fact[MAXN], n, m, k, s;
pair<long long int, long long int> A[MAXK];
long long int C(long long int x, long long int y) {
  if (x < 0 || y < 0 || y > x) return 0;
  return fact[x] * inv[y] % MOD * inv[x - y] % MOD;
}
int main() {
  fact[0] = inv[0] = 1;
  for (long long int i = 1; i < MAXN; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    inv[i] = Pow(fact[i], MOD - 2, MOD);
  }
  scanf("%lld%lld%lld%lld", &n, &m, &k, &s);
  for (long long int i = 1; i <= k; i++) {
    scanf("%lld%lld", &A[i].first, &A[i].second);
  }
  A[0] = {1, 1};
  A[k + 1] = {n, m};
  k++;
  sort(A, A + k + 1);
  for (long long int i = 0; i <= k; i++) {
    for (long long int j = 0; j < LOG; j++) {
      dp[i][j] = C(A[i].first - 1 + A[i].second - 1, A[i].first - 1);
      for (long long int l = 0; l < j; l++) {
        dp[i][j] = (dp[i][j] - dp[i][l] + MOD) % MOD;
      }
      for (long long int l = 0; l < i; l++) {
        long long int kirekhar =
            C(A[i].first - A[l].first + A[i].second - A[l].second,
              A[i].first - A[l].first);
        dp[i][j] = (dp[i][j] - dp[l][j] * kirekhar % MOD + MOD) % MOD;
      }
    }
  }
  long long int cnt = C(n - 1 + m - 1, n - 1), ans = 0;
  for (long long int i = 1; i < LOG; i++) {
    ans = (ans + dp[k][i] * s % MOD) % MOD;
    cnt = (cnt - dp[k][i] + MOD) % MOD;
    s = s + 1 >> 1;
  }
  ans = (ans + cnt) % MOD;
  printf("%lld\n", ans * Pow(C(n - 1 + m - 1, n - 1), MOD - 2, MOD) % MOD);
  return 0;
}
