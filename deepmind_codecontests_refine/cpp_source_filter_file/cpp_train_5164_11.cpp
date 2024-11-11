#include <bits/stdc++.h>
using namespace std;
long long fact[200000 + 5];
long long invmodf[200000 + 5];
long long mod = 1000000007ll;
long long comb(long long n, long long p) {
  return (((fact[n] * invmodf[p]) % mod) * invmodf[n - p]) % mod;
}
long long bexp(long long b, long long e) {
  if (b == 0ll) return 0;
  if (e == 0ll) return 1ll;
  if (e == 1ll) return b;
  long long x = bexp((b * b) % mod, e / 2ll);
  if (e % 2 == 1ll) x = (x * b) % mod;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fact[0] = 1;
  invmodf[0] = 1;
  for (int i = 1; i <= 200000 + 3; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
    invmodf[i] = bexp(fact[i], mod - 2ll);
  }
  long long n;
  cin >> n;
  if (n == 1ll) {
    long long a;
    cin >> a;
    cout << a << '\n';
    return 0;
  }
  if (n == 2ll) {
    long long a, b;
    cin >> a >> b;
    cout << (a + mod - b) % mod;
    return 0;
  }
  if (n == 3ll) {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << (mod + a + 2ll * b - c) % mod << '\n';
    return 0;
  }
  vector<long long> num(n + 4, 0);
  long long sum0 = 0;
  long long sum1 = 0;
  for (int i = 0; i < n; ++i) cin >> num[i];
  while (n % 4ll != 0) {
    for (long long i = 0ll; i < n - 1ll; ++i) {
      if (i % 2ll == 0ll)
        num[i] = (num[i] + num[i + 1]);
      else
        num[i] = (num[i] - num[i + 1]);
    }
    n--;
  }
  for (long long i = 0; i < n; i += 2ll) {
    sum0 += comb((n / 2ll) - 1ll, i / 2ll) * num[i];
    sum0 %= mod;
  }
  for (long long i = 1; i < n; i += 2ll) {
    sum1 += comb((n / 2ll) - 1ll, (i - 1ll) / 2ll) * num[i];
    sum1 %= mod;
  }
  cout << (sum0 + mod * 3ll - sum1) % mod << '\n';
  return 0;
}
