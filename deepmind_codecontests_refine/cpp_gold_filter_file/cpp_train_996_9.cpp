#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7, N = 1e3 + 10;
void test() {
  ll a, b;
  cin >> a >> b;
  ll c, d;
  cin >> c >> d;
  ll mn = 1e18;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      if (b + a * i == d + c * j) {
        mn = min(mn, b + a * i);
      }
    }
  }
  mn = (mn == (ll)1e18 ? -1 : mn);
  cout << mn << '\n';
  return;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll tt = 1;
  for (ll t = 1; t <= tt; ++t) {
    test();
  }
  return 0;
}
