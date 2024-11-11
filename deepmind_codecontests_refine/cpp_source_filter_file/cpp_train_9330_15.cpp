#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000000;
const signed long long int MOD = 1000000007;
signed long long int modpow(signed long long int n, int p) {
  signed long long int A = 1;
  while (p != 0) {
    if (p & 1) {
      A *= n;
      A %= MOD;
    }
    p >>= 1;
    n *= n;
    n %= MOD;
  }
  return A;
}
signed long long int modinv(signed long long int n) {
  return modpow(n, MOD - 2);
}
static signed long long int fl[MAX_N + 1];
static signed long long int fn[MAX_N + 1];
signed long long int choose(int n, int k) {
  if (k == 0 || k == n)
    return 1;
  else
    return (fl[n] * modinv(fl[k])) % MOD * modinv(fl[n - k]) % MOD;
}
int main() {
  int i, N, K;
  signed long long int p, T, U, u;
  fl[0] = 1;
  for (i = 1; i <= MAX_N; i++) fl[i] = (fl[i - 1] * i) % MOD;
  while (scanf("%d %d", &N, &K) == 2) {
    p = 1;
    fn[0] = 1;
    fn[1] = 1;
    for (i = 2; i <= N; i++)
      if (K == 1)
        fn[i] = 1;
      else {
        fn[i] = fn[i - 1] + fn[i - 1] * (i - 1);
        if (i > K) fn[i] -= fn[i - K - 1] * p * (i - 1);
        fn[i] %= MOD;
        fn[i] += MOD;
        fn[i] %= MOD;
        p *= i - 1;
        p %= MOD;
        if (i > K) {
          p *= modinv(i - K);
          p %= MOD;
        }
      }
    T = fl[N];
    U = 0;
    for (i = 1; i <= N; i++) {
      u = choose(N - 1, i - 1);
      u *= fl[N - i];
      u %= MOD;
      u *= fn[i - 1];
      u %= MOD;
      U += u;
      U %= MOD;
    }
    printf(
        "%I64d"
        "\n",
        (T - U + MOD) % MOD);
  }
  return 0;
}
