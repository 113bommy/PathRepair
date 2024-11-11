#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long fact[1000010];
long long pw(long long b, long long p) {
  if (p == 0) return 1LL;
  if (p == 1) return b;
  long long x = pw(b, p / 2) % mod;
  if (p % 2) return (((x * x) % mod) * b) % mod;
  return (x * x) % mod;
}
long long P(long long n, long long r) {
  return (fact[n] * pw((fact[r] * fact[n - r]) % mod, mod - 2)) % mod;
}
int main() {
  fact[0] = 1;
  for (long long i = 1; i < 1000010; i++) fact[i] = (i * fact[i - 1]) % mod;
  long long a, b, n;
  while (cin >> a >> b >> n) {
    long long res = 0;
    for (int i = 0; i <= n; i++) {
      long long sum = i * a + (n - i) * b;
      bool ok = 1;
      while (sum && ok) {
        if (sum % 10 != a && sum % 10 != b) ok = 0;
        sum /= 10;
      }
      if (ok) res = (res + P(n, i)) % mod;
    }
    cout << res << endl;
  }
  return 0;
}
