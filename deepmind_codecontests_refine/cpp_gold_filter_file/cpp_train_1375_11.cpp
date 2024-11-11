#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
const int mod = 998244353;
const ll inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-7;
const int N = 1e6 + 5;
struct HASH {
  ll x, y;
  const int MOD1 = 1e9 + 7;
  const int MOD2 = 1e9 + 9;
  const int P1 = 73;
  const int P2 = 79;
  HASH() { x = y = 0; }
  void add(ll val) {
    x = (x * P1 + val) % MOD1;
    y = (y * P2 + val) % MOD2;
  }
  pll get() { return {x, y}; }
};
ll a[N];
map<pll, int> mp;
const int LOG = 31;
int n;
const int DELTA = 8;
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int half = LOG / 2;
  {
    for (int mask = 0; mask < (1 << half); ++mask) {
      for (int rep = -DELTA; rep <= DELTA; ++rep) {
        HASH myhash;
        for (int i = 0; i < n; ++i) {
          ll cur = (a[i] & ((1 << half) - 1)) ^ mask;
          myhash.add(__builtin_popcount(cur) + rep);
        }
        mp[myhash.get()] = mask;
      }
    }
  }
  {
    for (int mask = 0; mask < (1 << (LOG - half)); ++mask) {
      for (int rep = -DELTA; rep <= DELTA; ++rep) {
        HASH myhash;
        for (int i = 0; i < n; ++i) {
          ll cur = (a[i] >> half) ^ mask;
          myhash.add(30 - __builtin_popcount(cur) + rep);
        }
        if (mp.count(myhash.get())) {
          ll res = ((mask << half) ^ mp[myhash.get()]);
          cout << res << "\n";
          return;
        }
      }
    }
  }
  cout << -1;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int tt = 1;
  while (tt--) {
    solve();
    cout << "\n";
  }
}
