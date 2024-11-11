#include <bits/stdc++.h>
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
using namespace std;
const int inf = 1e9 + 228;
const long long infll = 1e18;
const long long MOD = 1e9 + 7;
const long double eps = 1e-5;
const int K = 31;
const long double eps2 = 1e-9;
const long long MOD2 = 998244353;
const long long dosz = 5e5;
const long long SZ = (1 << 18);
const long double PI = 3.1415926535;
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
void solve() {
  int a, b;
  cin >> a >> b;
  cout << (a + b) / 2 << " " << min(a, b) << endl;
}
signed main() {
  fast_io();
  cout << fixed << setprecision(3);
  int q = 1;
  while (q--) solve();
}
