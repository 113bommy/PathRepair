#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long gcd(long long a, long long b) { return (a == 0) ? b : gcd(b % a, a); }
long long cnt1(long long x) {
  long long cnt = 0;
  while (x > 0) x &= x - 1, cnt++;
  return cnt;
}
long long fact(long long n) { return n == 0 ? 1LL : n * fact(n - 1); }
long long fact(long long n, long long p) {
  return n == 0 ? 1LL : n * fact(n - 1) % p;
}
long long cnk(long long n, long long k) {
  return n == 1 || k == 1 ? 1 : cnk(n - 1, k) + cnk(n - 1, k - 1);
}
long long pow(long long a, long long n, long long p) {
  if (n == 0) return 1;
  long long t = pow(a, n / 2, p);
  return t * t * (n % 2 ? a : 1);
}
long long cnk(long long n, long long k, long long p) {
  return fact(n, p) * pow(fact(k, p), p - 2, p) * pow(fact(n - k, p), p - 2, p);
}
long long updiv(long long a, long long b) { return (a + b - 1) / b; }
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (long long i = 0; i < v.size(); i++) is >> v[i];
  return is;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> v) {
  for (long long i = 0; i < v.size(); i++) os << v[i] << ' ';
  os << '\n';
  return os;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long n, q;
  cin >> n >> q;
  for (long long i = 0; i < q; i++) {
    long long x, y;
    cin >> x >> y;
    long long t = updiv((x - 1) * n + y, 2);
    if ((x + y) % 2) t += updiv(((n) * (n)), 2);
    cout << t << '\n';
  }
}
