#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vtll = vector<tll>;
using gr = vector<vll>;
using wgr = vector<vpll>;
void add_edge(gr& g, ll first, ll second) {
  g[first].push_back(second);
  g[second].push_back(first);
}
void add_edge(wgr& g, ll first, ll second, ll z) {
  g[first].emplace_back(second, z);
  g[second].emplace_back(first, z);
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  cerr << ' ' << p.first << ',' << p.second;
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto first : v) os << ' ' << first;
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (auto first : v) os << ' ' << first;
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& v) {
  for (auto first : v) os << ' ' << first;
  return os;
}
struct d_ {
  template <typename T>
  d_& operator,(const T& first) {
    cerr << ' ' << first;
    return *this;
  }
} d_t;
bool ask(vll v) {
  auto [first, second, z] = tll{v[0], v[1], v[2]};
  cout << "? " << first + 1 << " " << second + 1 << " " << z + 1 << endl;
  bool ret;
  cin >> ret;
  return ret;
}
pll getExamples(vll r, vll b) {
  vll v = r;
  for (auto i : b) v.push_back(i);
  for (ll i(1); i < 3; i++) {
    bool cur = ask({v[i], v[i + 1], v[i + 2]});
    if (cur) return {v[i - 1], v[i + 2]};
  }
  return {v[2], v[5]};
}
void solve() {
  ll n;
  cin >> n;
  ll a0 = -1, a1 = -1;
  set<tll> tried;
  vll type(n / 3);
  vector<bool> vis(n);
  vector<vll> V(2);
  for (ll i(0); i < n / 3; i++) {
    vll v;
    for (ll j(0); j < 3; j++) v.push_back(3 * i + j);
    type[i] = ask(v);
    V[type[i]] = v;
  }
  auto [R, B] = getExamples(V[0], V[1]);
  vll ret(n, -1);
  ret[R] = 0;
  ret[B] = 1;
  vll RB = {R, B};
  for (ll i(0); i < n / 3; i++) {
    ll tp = type[i];
    ll other = RB[!tp];
    vll v;
    for (ll j(0); j < 3; j++) {
      v.push_back(3 * i + j);
      ret[3 * i + j] = tp;
    }
    ll curother = -1;
    ll aa = ask({other, v[1], v[2]}) == tp;
    ll ab = ask({v[0], other, v[2]}) == tp;
    if (aa && ab) {
    } else {
      if (!aa)
        ret[v[0]] = !tp;
      else if (!ab)
        ret[v[1]] = !tp;
      else
        ret[v[2]] = !tp;
    }
  }
  ll cnt = 0;
  for (ll i(0); i < n; i++) cnt += ret[i] == 0;
  cout << "! ";
  cout << cnt << " ";
  for (ll i(0); i < n; i++)
    if (ret[i] == 0) cout << i + 1 << " ";
  cout << endl;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  srand(time(0));
  ll _T;
  cin >> _T;
  for (ll _(0); _ < _T; _++) solve();
  return 0;
}
