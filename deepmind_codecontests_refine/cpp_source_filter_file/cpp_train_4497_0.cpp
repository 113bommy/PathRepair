#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,mmx,tune=native")
long long n, k, h[200005], ans = 1, mod = 1e9 + 7, cnt, fact[200005],
                           ifact[200005];
long long pang(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long z = pang(x, y / 2);
  return z * z % mod * pang(x, y % 2) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> h[i];
  for (long long i = 1; i <= n; i++) {
    if (h[i] == h[i % n + 1]) {
      ans = (ans * k) % mod;
    } else
      cnt++;
  }
  fact[0] = ifact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    ifact[i] = (ifact[i - 1] * pang(i, mod - 2)) % mod;
  }
  long long mult = pang(k, cnt);
  for (long long i = 0; i <= cnt / 2; i++) {
    long long temp = fact[cnt] * ifact[i] % mod * ifact[i] % mod *
                     ifact[cnt - 2 * i] % mod * pang(k - 2, cnt - 2 * i) % mod;
    mult = (mult - temp) % mod;
  }
  mult = (mult + 2 * mod) % mod;
  mult = (mult * ifact[2]) % mod;
  mult = (mult * ans) % mod;
  cout << mult << '\n';
}
