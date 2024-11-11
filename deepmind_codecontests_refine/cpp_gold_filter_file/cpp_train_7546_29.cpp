#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
const long long MOD = 1e9 + 7;
long long fact[MAX];
void calculate() {
  fact[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
}
long long modExp(long long b, long long p) {
  long long res = 1;
  while (p > 0) {
    if (p & 1) res = (res * b) % MOD;
    b = (b * b) % MOD, p >>= 1;
  }
  return res;
}
long long modInverse(long long n) { return modExp(n, MOD - 2); }
long long nCr(long long n, long long r) {
  return (fact[n] * modInverse(fact[n - r]) % MOD * modInverse(fact[r]) % MOD) %
         MOD;
}
void add(long long &a, long long b) {
  b %= MOD;
  a = (a + b) % MOD;
}
void mul(long long &a, long long b) {
  b %= MOD;
  a = (a * b) % MOD;
}
void sub(long long &a, long long b) {
  b %= MOD;
  a = (a - b) % MOD;
  a = (a + MOD) % MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  calculate();
  int n;
  cin >> n;
  long long ans = 2 * nCr(2 * n - 1, n - 1) % MOD;
  sub(ans, n);
  cout << ans;
  return 0;
}
