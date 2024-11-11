#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    ll l, r;
    cin >> l >> r;
    if (r == 0) {
      cout << 0 << endl;
      continue;
    }
    if (l == r) {
      cout << r << endl;
      continue;
    }
    int ml = 0, mr = 0;
    for (int i = 0; i < 64; i++) {
      ll u = 1ll << i;
      if (u & l) ml = i;
      if (u & r) mr = i;
    }
    if (mr > ml) {
      ll ans = (1ll << (mr)) - 1;
      if ((1ll << (mr + 1)) - 1 == r) ans = r;
      cout << ans << endl;
    } else {
      for (int i = 62; i >= 0; i--) {
        ll u = (1ll << i) & l;
        ll v = (1ll << i) & r;
        if (u ^ v) {
          ll x = (1ll << (i + 1)) - 1;
          if ((r & x) == x) {
            cout << r << endl;
          } else {
            ll ans = r & ~(1ll << i);
            ans = ans | ((1ll << i) - 1);
            cout << ans << endl;
          }
          break;
        }
      }
    }
  }
}
