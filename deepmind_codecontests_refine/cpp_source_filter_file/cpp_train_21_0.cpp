#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}
ll S(ll n, ll k) { return 2 * (n - k); }
void solve() {
  int T;
  cin >> T;
  for (ll(q) = (1); (q) <= (T); (q)++) {
    ll n, l, r;
    cin >> n >> l >> r;
    ll length = r - l + 1;
    ll lk;
    for (ll(k) = (1); (k) <= (n - 1); (k)++) {
      if (l - S(n, k) >= 0)
        l -= S(n, k), r -= S(n, k);
      else {
        lk = k;
        break;
      }
    }
    vector<ll> res;
    {
      res.push_back(0);
      ll i = 0;
      for (ll(k) = (lk); (k) <= (n - 1); (k)++) {
        for (ll(j) = (k + 1); (j) <= (n); (j)++) {
          res.push_back(k);
          i++;
          if (i == r) goto hoge;
          res.push_back(j);
          i++;
          if (i == r) goto hoge;
        }
      }
      if (i < r) res.push_back(1), i++;
    hoge:
      assert(i == r);
    }
    for (ll(i) = (l); (i) <= (r); (i)++) {
      cout << res[i] << (i < r ? " " : "\n");
    }
  }
  return;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
