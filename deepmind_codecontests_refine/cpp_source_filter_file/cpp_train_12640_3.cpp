#include <bits/stdc++.h>
const int MAXM = 105;
const int LIM = 1e4;
const int ARSIZE = 1e4 + 5;
const int MOD = 1e9 + 7;
typedef int Arr[ARSIZE];
int M;
Arr X, sum, Y, DP[MAXM], fac, inv;
inline long long C(int n, int r) {
  return (long long)fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}
long long fast_pow(long long bs, int ex) {
  long long res = 1;
  for (; ex; ex >>= 1, bs = bs * bs % MOD)
    if (ex & 1) res = res * bs % MOD;
  return res;
}
void init();
int main() {
  init();
  scanf("%d", &M);
  int i, j, k;
  for (i = 1; i <= M; i++) {
    scanf("%d", X + i);
    sum[i] = sum[i - 1] + X[i];
  }
  for (i = 1; i <= M; i++) scanf("%d", Y + i);
  for (i = DP[0][0] = 1; i <= M; i++)
    for (j = 0; j <= sum[i]; j++)
      for (k = 0; k <= j && k <= Y[i]; k++)
        (DP[i][j] += DP[i - 1][j - k] * C(sum[i] - j + k, k) % MOD) %= MOD;
  int res = (long long)DP[M][sum[M]] * fac[sum[M]];
  for (i = 1; i <= M; i++) res = (long long)res * inv[X[i]] % MOD;
  printf("%d\n", res);
  return 0;
}
void init() {
  long long i;
  for (i = fac[0] = 1; i <= LIM; i++) fac[i] = i * fac[i - 1] % MOD;
  inv[LIM] = fast_pow(fac[LIM], MOD - 2);
  for (i = LIM - 1; i >= 0; i--) inv[i] = (i + 1) * inv[i + 1] % MOD;
}
