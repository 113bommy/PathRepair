#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using pii = pair<long long, long long>;
void xmax(long long& a, long long b) { a = max(a, b); }
void xmin(long long& a, long long b) { a = min(a, b); }
void print(vc<long long>& a, string second) {
  cerr << second << " : ";
  for (long long i = 0; i < a.size(); i++) {
    cerr << a[i] << " ";
  }
  cerr << endl;
}
long long mod = 998244353;
long long mod_p(long long b, long long e) {
  if (e == 0) return 1;
  if (e % 2 == 0) return mod_p(b * b % mod, e / 2);
  return b * mod_p(b, e - 1) % mod;
}
long long inv(long long x) { return mod_p(x, mod - 2); }
long long fac(long long a) {
  if (a == 0) return 1;
  return a * fac(a - 1) % mod;
}
void do_test() {
  long long n;
  cin >> n;
  vc<long long> a(2 * n);
  for (long long i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long small = 0;
  for (long long i = 0; i < n; i++) {
    small += a[i];
  }
  long long big = 0;
  for (long long i = n; i < 2 * n; i++) {
    big += a[i];
  }
  long long mult = inv(fac(n)) * inv(fac(n)) % mod;
  mult = (mult * fac(2 * n)) % mod;
  mult = (mult * ((big - small) % mod)) % mod;
  mult = (mod + mult) % mod;
  cout << mult << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  do_test();
}
