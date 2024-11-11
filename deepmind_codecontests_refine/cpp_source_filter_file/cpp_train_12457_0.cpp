#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 9;
long long pow_mod(long long x, long long n) {
  long long res;
  while (n) {
    if (n & 1) res = res * x % mod;
    n >>= 1;
    x = x * x % mod;
  }
  return res;
}
long long inv(long long x) { return pow_mod(x, mod - 2); }
int main() {
  long long n, a, b, k;
  string s;
  while (cin >> n >> a >> b >> k) {
    cin >> s;
    long long ans = 0;
    for (long long i = 0; i < k; i++) {
      if (s[i] == '+')
        ans = (ans + pow_mod(a, n - i) * pow_mod(b, i) + mod) % mod;
      else
        ans = (ans - pow_mod(a, n - i) * pow_mod(b, i) + mod) % mod;
    }
    long long m = (n + 1) / k;
    long long q = pow_mod(b, k) * inv(pow_mod(a, k)) % mod;
    if (q == 1)
      ans = ans * m % mod;
    else {
      ans = ans * (1 - pow_mod(q, m)) % mod;
      ans = ans * inv(1 - q) % mod;
    }
    cout << (ans + mod) % mod << endl;
  }
  return 0;
}
