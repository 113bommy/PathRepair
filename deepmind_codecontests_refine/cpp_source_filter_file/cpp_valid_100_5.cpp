#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 20;
const long long mod = 998244353;
long long fact[N];
map<long long, long long> vis;
long long ksm(long long a, long long b) {
  if (b == 0) return 1;
  if (b & 1)
    return a * ksm(a, b - 1) % mod;
  else {
    long long k = ksm(a, b / 2);
    return k * k % mod;
  }
}
long long C(long long m, long long n) {
  if (m == 0) return 1;
  return fact[n] * ksm(fact[m] * fact[n - m] % mod, mod - 2) % mod;
}
signed main() {
  fact[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vis.clear();
    long long mx = 0;
    for (long long i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      vis[x]++;
      mx = max(x, mx);
    }
    if (vis[mx] > 1)
      cout << fact[vis[mx]] << endl;
    else {
      if (vis[mx - 1] == 0) {
        cout << 0 << endl;
      } else {
        long long all = n - vis[mx] - vis[mx - 1];
        long long res = fact[n];
        for (long long i = vis[mx - 1] + 1; i <= n; i++) {
          res = ((res - C(n - i, all) * fact[i - 1] % mod * fact[n - i] % mod) +
                 mod) %
                mod;
        }
        cout << res << endl;
      }
    }
  }
}
