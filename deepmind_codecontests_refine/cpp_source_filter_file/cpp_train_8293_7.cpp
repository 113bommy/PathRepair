#include <bits/stdc++.h>
using namespace std;
const long long MAXN = (1LL << 20) + 10, MOD = 998244353;
void fi(const char* tem) {
  if (!strlen(tem)) return;
  char A[50];
  const char B[4] = {'.', 'i', 'n', 0}, C[5] = {'.', 'o', 'u', 't', 0};
  memset(A, 0, sizeof(A));
  sprintf(A, "%s%s", tem, B);
  freopen(A, "r", stdin);
  sprintf(A, "%s%s", tem, C);
  freopen(A, "w", stdout);
  return;
}
long long inv[MAXN], fac[MAXN], N;
long long ks(long long n, long long tim) {
  long long ret = 1;
  while (tim) {
    if (tim & 1) ret = ret * n % MOD;
    n = n * n % MOD;
    tim >>= 1;
  }
  return ret % MOD;
}
long long C(long long n, long long m) {
  return (n < m || m < 0) ? 0 : (fac[n] * inv[m] % MOD * inv[n - m] % MOD);
}
int main() {
  fi("");
  scanf("%lld", &N);
  long long tem = -ks(3, N * N + 1);
  inv[1] = inv[0] = fac[0] = fac[1] = 1;
  long long ans = 0;
  for (long long i = 2; i <= MAXN - 10; i++)
    inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD,
    fac[i] = fac[i - 1] * i % MOD;
  for (long long i = 2; i <= MAXN - 10; i++) inv[i] = inv[i - 1] * inv[i] % MOD;
  for (long long i = 1; i <= N; i++)
    (ans += 2 * C(N, i) * ks(-1, i + 1) % MOD * ks(3, i + N * (N - i)) % MOD +
            tem * C(N, i) % MOD * ks(ks(3, i * N), MOD - 2) % MOD * ks(-1, i) %
                MOD * ((ks(1 - ks(ks(3, N - i), MOD - 2), N) - 1) % MOD)) %=
        MOD;
  printf("%lld\n", (ans) % MOD);
  return 0;
}
