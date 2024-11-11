#include <bits/stdc++.h>
using namespace std;
int M, n, k;
long long int dp[1009][109][2];
long long int expmod(long long int base, long long int pow, long long int MOD) {
  if (pow == 0) return 1 % MOD;
  if (pow == 1) return base % MOD;
  long long int res = expmod(base, pow / 2, MOD);
  res = (res * res) % MOD;
  if (pow % 2 == 1) res = (res * base) % MOD;
  return res;
}
long long int memoize(int i, int j, int ch) {
  if (j == 0 && i == n && ch) return 1 % M;
  if (j == 0 && i < n && ch) return (9 * 1ll * expmod(10, n - i - 1, M)) % M;
  if (i >= n) return 0;
  if (dp[i][j][ch] != -1) return dp[i][j][ch];
  int dig = 0;
  long long int ans = 0;
  for (int q = int(dig); q <= int(9); q++) {
    int nj = ((expmod(10, i, k) * q) % k + j) % k;
    int nch = (ch | (q > 0));
    ans += memoize(i + 1, nj, nch);
    if (ans > M) ans -= M;
  }
  return dp[i][j][ch] = ans;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  scanf("%d", &k);
  scanf("%d", &M);
  long long int ans = memoize(0, 0, 0);
  printf("%lld\n", ans);
  return 0;
}
