#include <bits/stdc++.h>
using namespace std;
int const H = 1e5 + 3;
long long fact[2 * H];
int const N = 2e3 + 3;
long long d[N];
pair<int, int> rc[N];
long long powmod(long long a, long long b, long long p) {
  a %= p;
  if (a == 0) return 0;
  long long product = 1;
  while (b > 0) {
    if (b & 1) {
      product *= a;
      product %= p;
      --b;
    }
    a *= a;
    a %= p;
    b >>= 2;
  }
  return product;
}
long long inv(long long a, long long p) { return powmod(a, p - 2, p); }
long long mod = 1e9 + 7;
long long nCk(long long n, long long k, long long p) {
  return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fact[0] = 1;
  for (int i = (1); i < (2 * H); ++i) {
    fact[i] = ((long long)i * fact[i - 1]) % mod;
  }
  int h, w, n;
  cin >> h >> w >> n;
  for (int i = (0); i < (n); ++i) {
    cin >> rc[i].first >> rc[i].second;
  }
  sort(rc, rc + n);
  rc[n] = {h, w};
  for (int i = (0); i < (n + 1); ++i) {
    d[i] = nCk((rc[i].first + rc[i].second - 2), rc[i].first - 1, mod);
    for (int j = (0); j < (i); ++j) {
      long long dx = rc[i].first - rc[j].first;
      long long dy = rc[i].second - rc[j].second;
      if (dx < 0 || dy < 0) continue;
      d[i] -= (d[j] * nCk(dx + dy, dx, mod)) % mod;
      d[i] += mod;
      d[i] %= mod;
    }
  }
  cout << d[n] << '\n';
  return 0;
}
