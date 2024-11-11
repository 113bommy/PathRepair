#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T1, typename T2>
inline void chkmin(T1 &x, const T2 &y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1 &x, const T2 &y) {
  if (x < y) x = y;
}
struct pt {
  ll x, y, z;
  pt() {}
};
ld dist(pt a, pt b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
              (a.z - b.z) * (a.z - b.z));
}
ll n;
vector<pt> a;
void solve() {
  cin >> n;
  a.resize(n);
  for (auto &i : a) cin >> i.x >> i.y >> i.z;
  ld ans = 1e18;
  for (ll i = 1; i < n; i++) {
    for (ll j = 1; j < i; j++) {
      chkmin(ans, (dist(a[0], a[i]) + dist(a[0], a[j]) + dist(a[i], a[j])) / 2);
    }
  }
  cout.precision(20);
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t = 1;
  while (t--) solve();
  return 0;
}
