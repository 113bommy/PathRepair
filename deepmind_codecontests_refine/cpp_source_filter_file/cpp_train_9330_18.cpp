#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
using namespace std;
template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}
template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}
const int N = 1e6 + 5;
const int MOD = round(1e9 + 7);
const int FN = N;
int fact[FN];
int inv_fact[FN];
int power(int base, int p) {
  if (p == 0) return 1;
  int res = power(base, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * base % MOD;
  }
  return res;
}
int modInverse(int x) { return power(x, MOD - 2); }
void buildFactorial() {
  fact[0] = 1;
  inv_fact[0] = 1;
  for (int i = 1; i < FN; ++i) {
    fact[i] = 1LL * i * fact[i - 1] % MOD;
    inv_fact[i] = modInverse(fact[i]);
  }
}
int f[N];
int g[N];
int k;
void build() {
  buildFactorial();
  f[0] = 1;
  g[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = g[i - 1];
    if (i - 1 - k >= 0) {
      f[i] = (f[i] - g[i - 1 - k] + MOD) % MOD;
    }
    f[i] = 1LL * f[i] * fact[i - 1] % MOD;
    g[i] = 1LL * f[i] * inv_fact[i] % MOD;
    g[i] = (g[i - 1] + g[i]) % MOD;
  }
}
int nCr(int n, int r) {
  int res = fact[n];
  res = 1LL * res * inv_fact[r] % MOD;
  res = 1LL * res * inv_fact[n - r] % MOD;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n >> k;
  build();
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int t = 1LL * f[i - 1] * nCr(n - 1, i - 1) % MOD;
    t = 1LL * t * fact[n - i];
    res = (res + t) % MOD;
  }
  cout << (fact[n] - res + MOD) % MOD << '\n';
  return 0;
}
