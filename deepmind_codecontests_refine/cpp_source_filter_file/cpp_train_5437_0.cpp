#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int MAX = 1005;
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
    if (p & 1) {
      res = (res * b) % MOD;
    }
    b = (b * b) % MOD;
    p >>= 1;
  }
  return res;
}
long long modInverse(long long n) { return modExp(n, MOD - 2); }
long long nCr(long long n, long long r) {
  return (fact[n] * modInverse(fact[n - r]) % MOD * modInverse(fact[r]) % MOD) %
         MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  calculate();
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + nCr(m + n - i, n - i) * nCr(m + i - 2, i - 1)) % MOD;
  }
  cout << ans;
  return 0;
}
