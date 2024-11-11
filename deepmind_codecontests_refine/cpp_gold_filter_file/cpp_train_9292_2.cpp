#include <bits/stdc++.h>
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
using namespace std;
const long long inf = 1e9 + 228;
const long long infll = 1e18;
const long long MOD = 1e9 + 7;
const long double eps = 1e-5;
const long long K = 31;
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
  long long n, d, m;
  cin >> n >> d >> m;
  vector<long long> good;
  long long ans = 0;
  vector<long long> pref;
  for (long long i = 0; i < n; i++) {
    long long b;
    cin >> b;
    if (b <= m) {
      good.push_back(b);
    } else {
      pref.push_back(b);
    }
  }
  pref.push_back(inf);
  sort(pref.begin(), pref.end());
  sort(good.begin(), good.end());
  reverse(pref.begin(), pref.end());
  pref[0] = 0;
  reverse(good.begin(), good.end());
  for (long long i = 1; i < good.size(); i++) {
    good[i] += good[i - 1];
  }
  for (long long i = 1; i < pref.size(); i++) {
    pref[i] += pref[i - 1];
  }
  while (pref.size() < n + 228) {
    pref.push_back(pref.back());
  }
  ans = pref[(n + d) / (d + 1)];
  for (long long i = 0; i < good.size(); i++) {
    ans = max(ans, good[i] + pref[(n - i - 1 + d) / (d + 1)]);
  }
  cout << ans << endl;
}
signed main() {
  fast_io();
  cout << fixed << setprecision(3);
  long long q = 1;
  while (q--) solve();
}
