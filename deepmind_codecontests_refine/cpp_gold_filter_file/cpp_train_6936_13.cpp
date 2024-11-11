#include <bits/stdc++.h>
using namespace std;
mt19937 rnd;
const long long maxn = 2e6 + 5;
const long long mod = 1e9 + 7;
long long fac[maxn];
long long inv[maxn];
vector<char> prime(maxn, true);
long long spf[maxn];
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a % mod;
  if (b == 2) return (a * a) % mod;
  if (b % 2 == 0) return binpow((a * a) % mod, b / 2);
  if (b % 2 == 1) return (a * binpow((a * a) % mod, b / 2)) % mod;
}
void buildprimes() {
  prime[0] = prime[1] = false;
  for (long long i = 2; i < maxn; ++i) {
    if (prime[i]) {
      spf[i] = i;
      if (i * 1ll * i < maxn) {
        for (long long j = i * i; j < maxn; j += i) {
          prime[j] = false;
          spf[j] = i;
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fac[1] = fac[0] = 1;
  for (long long i = 2; i < maxn; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
  for (long long i = 1; i < maxn; i++) {
    inv[i] = binpow(fac[i], mod - 2);
  }
  buildprimes();
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (y == 1) {
      cout << "1\n";
      continue;
    }
    long long ans = 1;
    ans = binpow(2, y - 1);
    while (x > 1) {
      long long cur = 0;
      long long p = spf[x];
      while (x % p == 0) {
        x /= p;
        cur++;
      }
      long long C = (((fac[cur + y - 1] * inv[y - 1]) % mod) * inv[cur]) % mod;
      ans = (ans * C) % mod;
    }
    cout << ans << '\n';
  }
  return 0;
}
