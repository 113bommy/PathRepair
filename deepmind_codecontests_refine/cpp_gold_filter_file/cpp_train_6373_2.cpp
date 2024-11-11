#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 7;
const long long INF = 1LL << 60;
const long long mod = 1e9 + 7;
const long double eps = 1e-8;
const long double pi = acos(-1.0);
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<long long> pf(long long x) {
  vector<long long> res;
  for (long long i = 2; i * i <= x; ++i) {
    if (x % i != 0) continue;
    while (x % i == 0) {
      x /= i;
    }
    res.push_back(i);
  }
  if (x != 1) res.push_back(x);
  return res;
}
void solve() {
  long long a, m;
  cin >> a >> m;
  long long d = gcd(a, m);
  m /= d, a /= d;
  vector<long long> p = pf(m);
  cerr << p.size() << endl;
  long long ans = 0;
  for (long long bit = 0; bit < (1 << ((long long)p.size())); ++bit) {
    long long cnt = __builtin_popcount(bit);
    long long f = 1LL;
    for (long long i = 0; i < (long long)p.size(); i++) {
      if (bit & (1 << i)) {
        f *= p[i];
      }
    }
    if (cnt % 2 == 0) {
      ans += (a + m - 1) / f - (a - 1) / f;
    } else {
      ans -= (a + m - 1) / f - (a - 1) / f;
    }
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) solve();
  return 0;
}
