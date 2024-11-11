#include <bits/stdc++.h>
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double EPS = 0.001;
const long double EPS2 = 1e-6;
const long double PI = acos(-1);
const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int a228 = 18;
const int inf = 1e9;
const long long kekmod = 1791791791;
const long long bestmod = 1148822869;
const long long INF = 4e18;
const int mod = MOD7;
const int MAXN = 200228;
long long fact[MAXN];
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long inv(long long a) { return binpow(a, mod - 2); }
long long cnk(long long n, long long k) {
  if (k > n || k < 0) return 0;
  return fact[n] * inv(fact[n - k]) % mod * inv(fact[k]) % mod;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  srand(time(NULL));
  fact[0] = 1;
  for (long long i = 1; i < MAXN; ++i) fact[i] = fact[i - 1] * i % mod;
  long long n;
  cin >> n;
  n = 2 * n - 1;
  long long x = 0;
  if (n % 2)
    x = cnk(n, n / 2 + 1);
  else
    x = cnk(n, n / 2);
  x %= mod;
  x *= 2;
  x %= mod;
  x -= n / 2 + 1;
  x += mod;
  x %= mod;
  cout << x;
}
