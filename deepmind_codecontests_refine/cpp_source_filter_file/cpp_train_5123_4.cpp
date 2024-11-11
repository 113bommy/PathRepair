#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long n, rez, inv[101], nr;
long long lgpow(long long a, long long b) {
  long long ans = 1;
  long long p = a;
  while (b) {
    if (b % 2 == 1) ans = (ans * p) % mod;
    p = (p * p) % mod;
    b /= 2;
  }
  return ans;
}
long long INV(long long x) { return lgpow(x, mod - 2); }
int main() {
  cin >> n;
  for (long long i = 1; i <= 100; i++) inv[i] = INV(i);
  rez = 1;
  for (int i = 1; i <= n; i++) {
    cin >> nr;
    if (i == 1)
      rez = (100LL * inv[nr]) % mod;
    else
      rez = (100LL * inv[nr] * (rez + 1)) % mod;
  }
  cout << rez;
  return 0;
}
