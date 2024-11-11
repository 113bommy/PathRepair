#include <bits/stdc++.h>
using namespace std;
const bool ready = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  return true;
}();
const double PI = acos(-1);
using ll = long long;
using pii = pair<ll, ll>;
using pdd = pair<double, double>;
using vd = vector<double>;
using vb = vector<bool>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;
void solve() {
  ll n;
  cin >> n;
  ;
  ll m;
  cin >> m;
  ;
  vb sx(n + 1);
  vb sy(n + 1);
  for (ll i = 0; i < m; i++) {
    ll x;
    cin >> x;
    ;
    ll y;
    cin >> y;
    ;
    sx[x] = true;
    sy[y] = true;
  }
  ll ans = 0;
  for (ll i = 2; i < n / 2 + 1; i++) {
    if (!sy[n - i + 1]) ans++;
    if (!sy[i]) ans++;
    if (!sx[n - i + 1]) ans++;
    if (!sx[i]) ans++;
  }
  if (n & 1) {
    if ((!sx[n / 2 + 1]) && (!sy[n / 2 + 1])) ans++;
  }
  cout << ans << endl;
}
signed main() { solve(); }
