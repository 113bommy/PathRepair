#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
long long int fact[N];
void calcFactorial() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = (i * fact[i - 1]) % MOD;
  }
}
long long int power(long long int b, long long int po, long long int mod) {
  long long int ret = 1;
  while (po) {
    if (po & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    po >>= 1;
  }
  return ret;
}
long long int mulInv(long long int x, long long int mod) {
  return power(x, mod - 2, mod);
}
long long int C(long long int n, long long int k) {
  return (fact[n] * mulInv(fact[n - k] * fact[k] % MOD, MOD)) % MOD;
}
int main() {
  calcFactorial();
  long long int n, m, k;
  scanf("%lld %lld %lld", &n, &m, &k);
  if (2 * k <= m - 1 && 2 * k <= n - 1)
    cout << (C(n - 1, 2 * k) * C(m - 1, 2 * k)) % MOD;
  else
    cout << 0;
  return 0;
}
