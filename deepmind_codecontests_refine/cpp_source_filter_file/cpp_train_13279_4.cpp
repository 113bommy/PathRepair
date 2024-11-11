#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using gr = vector<vll>;
using wgr = vector<vpll>;
struct d_ {
  template <typename T>
  d_& operator,(const T& x) {
    cerr << ' ' << x;
    return *this;
  }
  template <typename T>
  d_& operator,(const vector<T>& x) {
    for (auto x : x) cerr << ' ' << x;
    return *this;
  }
} d_t;
vector<string> sh = {"S", "M", "L", "XL", "XXL", "XXXL"};
int main(void) {
  ios_base::sync_with_stdio(false);
  vll v(6);
  for (ll i(0); i < 6; i++) cin >> v[i];
  ll n;
  cin >> n;
  vector<queue<ll>> q(6), q2(6);
  for (ll i(0); i < n; i++) {
    string cur;
    cin >> cur;
    ll pos;
    if ((pos = cur.find(",")) != string::npos) cur = cur.substr(0, pos);
    ll curi = find(begin(sh), end(sh), cur) - sh.begin();
    if (pos != string::npos)
      q2[curi].push(i);
    else
      q[curi].push(i);
  }
  vll ret(n);
  ll done = 0;
  for (ll i(0); i < 6; i++) {
    while (i && q2[i - 1].size() && v[i]) {
      auto cur = q2[i - 1].front();
      q2[i - 1].pop();
      v[i]--;
      ret[cur] = i;
      done++;
    }
    while (q[i].size() && v[i]) {
      auto cur = q[i].front();
      q[i - 1].pop();
      v[i]--;
      ret[cur] = i;
      done++;
    }
    while (i < 5 && q2[i].size() && v[i]) {
      auto cur = q2[i].front();
      q2[i].pop();
      v[i]--;
      ret[cur] = i;
      done++;
    }
  }
  if (done != n)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (ll i(0); i < n; i++) cout << sh[ret[i]] << endl;
  }
  return 0;
}
