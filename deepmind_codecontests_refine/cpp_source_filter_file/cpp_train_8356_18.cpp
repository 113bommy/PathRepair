#include <bits/stdc++.h>
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
ll gcd(ll n, ll m) {
  ll tmp;
  while (m != 0) {
    tmp = n % m;
    n = m;
    m = tmp;
  }
  return n;
}
ll lcm(ll n, ll m) { return abs(n) / gcd(n, m) * abs(m); }
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    auto f = [](ll n) -> tuple<ll, ll, ll> {
      for (ll i = 0; i <= n / 7; ++i) {
        for (ll j = 0; j <= (n - 7 * i) / 5; ++j) {
          for (ll k = 0; k <= (n - 7 * i - 7 * j) / 3; ++k) {
            if (3 * k + 5 * j + 7 * i == n) {
              return {i, j, k};
            }
          }
        }
      }
      return {-1, -1, -1};
    };
    auto [x, y, z] = f(n);
    if (x == -1)
      cout << -1 << "\n";
    else {
      cout << z << " " << y << " " << x << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);
  solve();
  return 0;
}
