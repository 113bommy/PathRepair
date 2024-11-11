#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;
ll n, a, b, t, l, m;
int f(ll x) {
  if ((ll)a * (x - l + 1) +
              (ll)b * (x * (x - 1) / 2 - (l - 1) * (ll)(l - 2) / 2) <=
          m * t and
      a + (ll)b * (x - 1) <= t)
    return 1;
  else
    return 0;
}
void code() {
  cin >> a >> b >> n;
  for (int i = 0; i < n; i++) {
    cin >> l >> t >> m;
    ll lo = l, hi = 1e6;
    while (lo < hi) {
      ll mid = lo + (hi - lo + 1) / 2;
      if (f(mid))
        lo = mid;
      else
        hi = mid - 1;
    }
    cout << (!f(lo) ? -1ll : lo) << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t-- > 0) {
    code();
  }
}
