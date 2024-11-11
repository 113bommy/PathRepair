#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long pwr(long long a, long long b) {
  if (b == 0)
    return 1;
  else {
    long long temp = pwr(a, b / 2);
    return (b & 1) ? ((temp * temp) % MOD * a) % MOD : (temp * temp) % MOD;
  }
}
long long fac[1000003], facmod[1000003];
void precompute() {
  fac[0] = facmod[0] = 1;
  for (long long i = 1; i <= 10000; i++) {
    fac[i] = (fac[i - 1] * i) % MOD;
    facmod[i] = pwr(fac[i], MOD - 2);
  }
}
long long C(long long n, long long k) {
  return ((fac[n] * facmod[k]) % MOD * facmod[n - k]) % MOD;
}
long long P(long long n, long long k) { return (fac[n] * facmod[n - k]) % MOD; }
long long frs(long long n, long long k) {
  return (k * pwr(n, n - k - 1)) % MOD;
}
int main() {
  long long n, m, a, b;
  scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
  precompute();
  long long res = 0;
  for (long long i = 2; i <= n; i++) {
    if (i - 2 > m - 1) break;
    long long A = (P(n - 2, i - 2) * C(m - 1, i - 2)) % MOD;
    long long B = (i == n) ? 1 : frs(n, i);
    long long D = pwr(m, n - i);
    res += ((A * B) % MOD * D) % MOD;
    res %= MOD;
  }
  printf("%lld\n", res);
}
