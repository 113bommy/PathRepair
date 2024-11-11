#include <bits/stdc++.h>
using namespace std;
template <class T>
int chkmax(T& a, T b) {
  if (b > a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
int chkmin(T& a, T b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class iterator>
void output(iterator begin, iterator end, ostream& out = cerr) {
  while (begin != end) {
    out << (*begin) << " ";
    begin++;
  }
  out << endl;
}
template <class T>
void output(T x, ostream& out = cerr) {
  output(x.begin(), x.end(), out);
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int mx = 2e5 + 228;
const long long MOD = 998244353;
int n, a[mx], cnt;
long long k, fact[mx], _fact[mx];
long long power(long long a, long long deg) {
  long long res = 1;
  while (deg) {
    if ((deg & 1LL) == 0) {
      a = (a * a) % MOD;
      deg >>= 1;
    } else {
      res = (res * a) % MOD;
      deg -= 1;
    }
  }
  return res;
}
long long inverse(long long a) { return power(a, MOD - 2); }
void calc_fact() {
  fact[0] = 1;
  for (int i = 1; i < mx; ++i) {
    fact[i] = (fact[i - 1] * (long long)i) % MOD;
  }
  for (int i = 0; i < mx; ++i) {
    _fact[i] = inverse(fact[i]);
  }
}
long long C(long long n, long long k) {
  if (k > n) {
    return 0;
  }
  return (fact[n] * _fact[k] % MOD * _fact[n - k] % MOD);
}
signed main() {
  fast_io();
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] != a[(i + 1) % n]) {
      cnt++;
    }
  }
  if (k == 1) {
    cout << 1 << endl;
    exit(0);
  }
  calc_fact();
  long long mult = power(k, n - cnt);
  long long all = power(k, cnt);
  for (int c = 0; 2 * c <= cnt; ++c) {
    long long cur =
        (C(cnt, c) * C(cnt - c, c) % MOD * power(k - 2, cnt - 2 * c)) % MOD;
    all = (all - cur + MOD) % MOD;
  }
  all = (all * inverse(2)) % MOD;
  mult = (mult * all) % MOD;
  cout << mult << endl;
}
