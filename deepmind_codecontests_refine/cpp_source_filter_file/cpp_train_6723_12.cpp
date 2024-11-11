#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a, b;
  cin >> a >> b;
  ll x = 0, y = 0;
  if (a < b || ((a - b) & 1))
    cout << -1;
  else {
    ll xandy = (a - b) >> 1;
    x = y = xandy;
    for (int i = 0; i < 64; i++) {
      if (b & (1LL << i)) {
        y += 1LL << i;
      }
    }
    cout << x << ' ' << y;
  }
  return 0;
}
