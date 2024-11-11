#include <bits/stdc++.h>
using namespace std;
long long N, M, A;
long long B[200010];
const int MOD = 998244353;
long long q(long long x) {
  long long a = A;
  long long ret = 1;
  while (x) {
    if (x & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    x >>= 1;
  }
  return ret;
}
long long f[200010];
long long inv2 = (MOD + 1) / 2;
long long g(long long x) {
  return ((q(2 * x) - q(x) + MOD) % MOD * inv2 % MOD + q(x)) % MOD;
}
int main() {
  scanf("%lld%lld%lld", &N, &M, &A);
  for (int i = 1; i <= M; i++) scanf("%lld", &B[i]);
  long long L = B[M];
  f[0] = 1;
  B[0] = 0;
  for (int i = 1; i <= M; i++) {
    f[i] = f[i - 1] * g(B[i] - B[i - 1]);
  }
  long long ans = f[M];
  ans *= q(N - 2 * L);
  ans %= MOD;
  printf("%lld\n", ans);
}
