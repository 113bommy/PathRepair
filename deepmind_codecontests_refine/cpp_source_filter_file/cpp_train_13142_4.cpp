#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mind(ll x) {
  ll ans = 9;
  while (x > 0) {
    ans = min(ans, x % 10);
    x /= 10;
  }
  return ans;
}
ll maxd(ll x) {
  ll ans = 0;
  while (x > 0) {
    ans = max(ans, x % 10);
    x /= 10;
  }
  return ans;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    ll a1, k;
    cin >> a1 >> k;
    while (k-- && mind(a1) != 0) {
      a1 += mind(a1) * maxd(a1);
    }
    cout << a1 << "\n";
  }
  return 0;
}
