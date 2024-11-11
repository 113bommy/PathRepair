#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ld PI = acos(-1);
const ll INF = 1e18;
struct edge {
  ll to, cost;
};
template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
void solve() {
  ll N;
  cin >> N;
  vector<pair<ll, ll> > ans;
  ll res = 1;
  while (2 * res <= N) {
    res *= 2;
  }
  int Z = N - res;
  int now = 2;
  while (now <= res) {
    for (ll i = 0; i < res / now; i++) {
      for (ll j = 0; j < now / 2; j++) {
        ans.push_back(pair<ll, ll>(now * i + j + 1, now * (i + 1) - j));
      }
    }
    now *= 2;
  }
  now = 2;
  while (now <= res) {
    for (ll i = 0; i < res / now; i++) {
      for (ll j = 0; j < now / 2; j++) {
        ans.push_back(pair<ll, ll>(Z + now * i + j + 1, Z + now * (i + 1) - j));
      }
    }
    now *= 2;
  }
  cout << ans.size() << '\n';
  for (ll i = 0; i < ans.size(); i++) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q = 1;
  while (q--) {
    solve();
  }
}
