#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 3e6;
const long long mod = 1e9 + 7;
const long double PI = acos((long double)-1);
long long pw(long long a, long long b, long long md = mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (a * res) % md;
    }
    a = (a * a) % md;
    b >>= 1;
  }
  return (res);
}
int q;
long long x, y, k;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> x >> y >> k;
    long long need = k * y + k - 1;
    x--;
    long long ans = (need + x - 1) / x;
    cout << ans + k << '\n';
  }
  return (0);
}
