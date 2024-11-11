#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v2 = vector<vector<T>>;
template <typename T>
inline v2<T> fill(int r, int c, const T& t) {
  return v2<T>(r, vector<T>(c, t));
}
ll a, b, c, d;
const ll INF = 1e18;
ll nc2(ll n) { return (n * (n - 1)) / 2; }
ll diff(ll n) { return a - b * d * (nc2(n) - nc2(n - 1)); }
ll value(ll n) {
  ll x = nc2(n);
  if (b * x > INF / d) {
    return INF;
  }
  return a * n - b * d * x;
}
void solve() {
  cin >> a >> b >> c >> d;
  if (a > b * c) {
    cout << "-1\n";
  } else {
    ll lo = 1;
    ll hi = c;
    ll ans = -INF;
    while (lo <= hi) {
      ll mid = (lo + hi) / 2;
      if (diff(mid) <= 0) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
      ans = max(ans, value(mid));
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    solve();
  }
  return 0;
}
