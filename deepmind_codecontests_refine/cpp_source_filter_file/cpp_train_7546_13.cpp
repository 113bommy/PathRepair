#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long FACT[2 * 100000 + 2];
void Factorial(int N, int MOD = -1) {
  if (MOD == -1) {
    FACT[0] = 1;
    for (int i = 1; i <= N; i++) {
      FACT[i] = FACT[i - 1] * (long long)i;
    }
  } else {
    FACT[0] = 1;
    for (int i = 1; i <= N; i++) {
      FACT[i] = (FACT[i - 1] * (long long)i) % MOD;
      FACT[i] %= MOD;
    }
  }
}
long long binpow(long long a, long long n, int MOD) {
  long long res = 1;
  a %= MOD;
  while (n) {
    if (n & 1) {
      res *= a;
      res %= MOD;
    }
    a *= a;
    a %= MOD;
    n >>= 1;
  }
  return res;
}
long long C(int N, int k) {
  long long ans = FACT[N];
  ans *= binpow(FACT[k] * FACT[N - k] % MOD, MOD - 2, MOD) % MOD;
  return ans % MOD;
}
int main() {
  int N;
  cin >> N;
  long long ans = 0;
  Factorial(100000 + 1, MOD);
  for (int j = N - 1, i = (N - 1) * 2; j >= 0; j--, i--) {
    ans += C(i, j);
    ans %= MOD;
  }
  cout << (MOD + 2 * ans - N) % MOD;
  return 0;
}
