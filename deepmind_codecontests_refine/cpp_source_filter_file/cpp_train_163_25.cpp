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
  ll k;
  cin >> k;
  ;
  ll p;
  cin >> p;
  ;
  set<ll> pers;
  for (ll i = 0; i < n; i++) {
    ll aux;
    cin >> aux;
    ;
    pers.insert(aux);
  }
  set<ll> keys;
  for (ll i = 0; i < k; i++) {
    ll aux;
    cin >> aux;
    ;
    keys.insert(aux);
  }
  ll l = 0;
  ll r = 1e10;
  while (l + 1 < r) {
    ll t = (l + r) / 2;
    set<ll> lpers = pers;
    set<ll> lkeys = keys;
    bool imp = false;
    while (lpers.size()) {
      auto it1 = lpers.begin();
      auto it2 = lpers.rbegin();
      ll lp;
      if (abs(*it1 - p) >= abs(*it2 - p))
        lp = *it1;
      else
        lp = *it2;
      lpers.erase(lp);
      if (abs(lp - p) > t) {
        imp = true;
        break;
      }
      if (lp >= p) {
        ll d = lp - p;
        ll mak = lp + (t - d) / 2;
        auto it = lkeys.upper_bound(mak);
        if (it != lkeys.begin()) {
          it--;
        }
        if (abs(lp - *it) + abs(*it - p) > t) {
          imp = true;
          break;
        }
        lkeys.erase(*it);
      } else {
        ll d = p - lp;
        ll mik = lp - (t - d) / 2;
        auto it = lkeys.lower_bound(mik);
        if (it == lkeys.end()) {
          imp = true;
          break;
        }
        if (abs(lp - *it) + abs(*it - p) > t) {
          imp = true;
          break;
        }
        lkeys.erase(*it);
      }
    }
    if (imp)
      l = t;
    else
      r = t;
  }
  cout << r << endl;
}
signed main() { solve(); }
