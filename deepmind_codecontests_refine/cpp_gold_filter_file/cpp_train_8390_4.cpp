#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:150777216")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rnd(123);
template <typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
  if (x < y) x = y;
}
const ll INF = 2e18;
ll add(ll a, ll b) {
  a += b;
  if (a >= INF) a = INF;
  return a;
}
ll mul(ll a, ll b) {
  if (!b) return 0;
  if (INF / b < a) return INF;
  return min(b * a, INF);
}
vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b) {
  vector<vector<ll>> ans(a.size(), vector<ll>(b[0].size()));
  for (ll k = 0; k < a[0].size(); ++k) {
    for (ll i = 0; i < a.size(); ++i) {
      for (ll j = 0; j < b[0].size(); ++j) {
        ans[i][j] = add(ans[i][j], mul(a[i][k], b[k][j]));
      }
    }
  }
  return ans;
}
vector<vector<ll>> binpow(vector<vector<ll>> a, ll k) {
  vector<vector<ll>> res(a.size(), vector<ll>(a.size()));
  for (ll i = 0; i < a.size(); ++i) res[i][i] = 1;
  while (k) {
    if (k & 1) res = mul(res, a);
    a = mul(a, a);
    k >>= 1;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.precision(20), cout.setf(ios::fixed);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& i : a) cin >> i;
  reverse((a).begin(), (a).end());
  while (!a.back()) a.pop_back();
  reverse((a).begin(), (a).end());
  if (a.size() >= 12) {
    ll cnt = 0;
    while (*max_element((a).begin(), (a).end()) < k) {
      vector<ll> pref = a;
      for (ll i = 1; i < pref.size(); ++i) pref[i] = add(pref[i - 1], a[i]);
      ++cnt;
      a = pref;
    }
    cout << cnt;
  } else {
    vector<vector<ll>> mtx(a.size(), vector<ll>(a.size()));
    for (ll i = 0; i < a.size(); ++i) {
      for (ll j = 0; j <= i; ++j) {
        mtx[i][j] = 1;
      }
    }
    vector<vector<ll>> nw;
    for (auto i : a) nw.push_back({i});
    ll l = -1, r = 1e18 + 1337;
    while (r - l > 1) {
      ll m = (l + r) / 2;
      auto nwa = binpow(mtx, m);
      auto tnw = mul(nwa, nw);
      ll mx = 0;
      for (auto j : tnw)
        for (auto i : j) mx = max(mx, i);
      if (mx >= k)
        r = m;
      else
        l = m;
    }
    cout << r;
  }
}
