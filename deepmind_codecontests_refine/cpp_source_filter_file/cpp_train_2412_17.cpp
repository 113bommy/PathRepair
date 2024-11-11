#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int E5 = 1e5;
ll f(ll x, ll y) { return x * x + 2 * x * y + x + 1; }
void solve() {
  ll r;
  cin >> r;
  for (ll x = 1; x * x <= r; ++x) {
    ll lef = 1, rig = 1e9;
    while (rig - lef > 1) {
      ll m = lef + (rig - lef) / 2;
      if (f(x, m) > r) {
        rig = m;
      } else {
        lef = m;
      }
    }
    if (f(x, lef) == r) {
      cout << x << ' ' << lef << '\n';
      return;
    }
  }
  cout << "NO\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
