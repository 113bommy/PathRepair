#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long modpow(long long x, long long n, long long m) {
  if (n == 0) return 1 % m;
  long long u = modpow(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) u = (u * x) % m;
  return u;
}
vector<long long> nfact, nfactInv;
long long ncr(long long n, long long r, int N = 300000) {
  if (!nfact.size()) {
    nfact.resize(N + 1);
    nfact[0] = 1;
    for (int i = 1; i <= N; i++) {
      nfact[i] = nfact[i - 1] * i;
      nfact[i] %= MOD;
    }
    nfactInv.resize(N + 1);
    for (int i = 0; i <= N; i++) {
      nfactInv[i] = modpow(nfact[i], MOD - 2, MOD);
    }
  }
  if (r > n || r < 0) return 0;
  long long d1 = nfactInv[r];
  long long d2 = nfactInv[n - r];
  long long mult = (d1 * d2) % MOD;
  return (nfact[n] * mult) % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long f, w, h;
  cin >> f >> w >> h;
  if (!f) {
    cout << (w > h);
    return 0;
  }
  if (!w) {
    cout << 1;
    return 0;
  }
  long long num = 0, denom = 0;
  for (long long i = 2; i <= w + h; i++) {
    long long x = i / 2, y = (i + 1) / 2, w2;
    denom += ncr(f - 1, x - 1) * ncr(w - 1, y - 1) % MOD;
    denom %= MOD;
    w2 = w - (h + 1) * y;
    num += ncr(f - 1, x - 1) * ncr(w2 + y - 1, y - 1) % MOD;
    num %= MOD;
    swap(x, y);
    denom += ncr(f - 1, x - 1) * ncr(w - 1, y - 1) % MOD;
    denom %= MOD;
    w2 = w - (h + 1) * y;
    num += ncr(f - 1, x - 1) * ncr(w2 + y - 1, y - 1) % MOD;
    num %= MOD;
  }
  cout << num * modpow(denom, MOD - 2, MOD) % MOD;
  return 0;
}
