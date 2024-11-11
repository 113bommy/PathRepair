#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const long long N = 0;
bool query(long long x, long long y) {
  cout << x << " " << y << endl;
  string s;
  cin >> s;
  if (s == "Bad") {
    exit(0);
  }
  if (s == "Yes") {
    if (x == y) exit(0);
    return 1;
  } else {
    return 0;
  }
}
void solve() {
  long long n, k;
  cin >> n >> k;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long L = 1, U = n;
  while (1) {
    while (U - L > 5 * k) {
      long long m = (L + U) / 2;
      if (query(L, m)) {
        U = m + k;
        L -= k;
      } else {
        L = m - k;
        U += k;
      }
      amax(L, 1);
      amin(U, n);
    }
    auto dist = uniform_int_distribution<long long>(L, U);
    long long x = dist(rng);
    query(x, x);
    L -= k;
    U += k;
    amax(L, 1);
    amin(U, n);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
