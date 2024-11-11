#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize 03
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
  long long t = pow(a, n >> 1, p);
  return t * t % p * (n & 1 ? a : 1) % p;
}
long long back(long long x, long long p) { return pow(x, p - 2, p); }
long long cnk(long long n, long long k, long long p) {
  return fact(n, p) * back(fact(k, p), p) % p * back(fact(n - k, p), p) % p;
}
template <class T>
istream &operator>>(istream &stream, vector<T> &v) {
  for (long long i = 0; i < (long long)v.size(); i++) stream >> v[i];
  return stream;
}
template <class T>
ostream &operator<<(ostream &stream, vector<T> v) {
  for (long long i = 0; i < (long long)v.size(); i++) stream << v[i] << ' ';
  stream << '\n';
  return stream;
}
const long long N = 1e+5, LOG = 20;
long long ans[N][LOG], ost[N][LOG];
signed main() {
  mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  cin >> a;
  for (long long log = 0; log < LOG; log++)
    for (long long i = 0; i < n; i++)
      if (log == 0)
        ost[i][log] = a[i];
      else {
        if (i + (1 << log) < N) {
          long long t = ost[i][log - 1] + ost[i + (1 << (log - 1))][log - 1];
          ost[i][log] = t % 10;
          ans[i][log] =
              ans[i][log - 1] + ans[i + (1 << (log - 1))][log - 1] + t / 10;
        }
      }
  long long q;
  cin >> q;
  while (q--) {
    long long l, r;
    cin >> l >> r;
    r--, l--;
    long long log;
    for (long long i = 0; i < LOG; i++)
      if ((1 << i) == r - l + 1) log = i;
    cout << ans[l][log] << '\n';
  }
}
