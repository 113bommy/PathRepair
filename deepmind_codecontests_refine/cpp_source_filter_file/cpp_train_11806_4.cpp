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
const ll INF = 1e9;
void solve() {
  ll n;
  cin >> n;
  ;
  ll m;
  cin >> m;
  ;
  multiset<pii> a1;
  multiset<pii> a2;
  for (ll i = 0; i < n; i++) {
    string s;
    cin >> s;
    ;
    ll v;
    cin >> v;
    ;
    if (s == "ATK")
      a1.insert({v, i});
    else
      a2.insert({v, i});
  }
  multiset<pii> b;
  for (ll i = 0; i < m; i++) {
    ll aux;
    cin >> aux;
    ;
    b.insert({aux, i});
  }
  multiset<pii> aa1 = a1;
  multiset<pii> aa2 = a2;
  multiset<pii> bb = b;
  while (aa2.size() && b.size()) {
    auto itdef = aa2.begin();
    auto it = bb.upper_bound({itdef->first, INF});
    if (it == bb.end()) break;
    aa2.erase(itdef);
    bb.erase(it);
  }
  ll ans2 = 0;
  if (aa2.size() == 0) {
    while (bb.size()) {
      auto itb = bb.rbegin();
      if (aa1.size()) {
        auto ita = aa1.rbegin();
        if (itb->first > ita->first) {
          ans2 += itb->first;
          ans2 -= ita->first;
          aa1.erase(*ita);
        } else
          break;
      } else {
        ans2 += itb->first;
      }
      bb.erase(*itb);
    }
  }
  ll ans1 = 0;
  while (b.size() && a1.size()) {
    auto itb = b.rbegin();
    auto ita = a1.begin();
    if (itb->first > ita->first) {
      ans1 += itb->first;
      ans1 -= ita->first;
      b.erase(*itb);
      a1.erase(*ita);
    } else
      break;
  }
  cout << max(ans1, ans2) << endl;
}
signed main() { solve(); }
