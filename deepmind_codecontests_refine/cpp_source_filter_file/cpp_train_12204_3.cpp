#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  mt19937_64 rnd(
      chrono::high_resolution_clock::now().time_since_epoch().count());
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &_ : a) cin >> _;
  ll ans = 0;
  for (auto x : a) ans += x % 2;
  for (int h = 0; h < 50; ++h) {
    int i = rnd() % n;
    for (ll x : {a[i] - 1, a[i], a[i] + 1}) {
      for (ll p = 2; x > 1; ++p) {
        if (p * p > x) p = x;
        if (x % p == 0) {
          do x /= p;
          while (x % p == 0);
          ll res = 0;
          for (ll x : a)
            if (x > p)
              res += min(x % p, p - x % p);
            else
              res += p - x % p;
          ans = min(ans, res);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
