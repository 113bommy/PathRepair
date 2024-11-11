#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());
template <typename T1, typename T2>
inline bool upmax(T1& a, T2 b) {
  return (a < b ? (a = b, true) : false);
}
template <typename T1, typename T2>
inline bool upmin(T1& a, T2 b) {
  return (b < a ? (a = b, true) : false);
}
const int maxn = (int)4e5 + 100;
const int maxlog = 21;
const int base = 1e9 + 7;
const long double eps = (long double)1e-9;
const long double PI = acos(-1.);
const int inf = 2e9;
const long long llinf = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long h, l;
  cin >> h >> l;
  double res =
      1. * l / sin(PI - 2. * asin(1. * l / sqrt(((h) * (h)) + ((l) * (l)))));
  cout << fixed << setprecision(10) << res - 1. * h << '\n';
  return 0;
}
