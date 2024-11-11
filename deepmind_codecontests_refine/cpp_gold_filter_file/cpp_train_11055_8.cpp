#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
template <typename T, typename Z>
inline T power(T base, Z exponent) {
  T ret = 1;
  for (; exponent > 0; exponent >>= 1, base *= base)
    if (exponent & 1) ret *= base;
  return ret;
}
template <typename Z>
Z gcd(const Z& a, const Z& b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename Z>
Z extended_gcd(const Z& a, const Z& b, Z& x, Z& y) {
  if (b == 0) return x = 1, y = 0, a;
  Z gcd = extended_gcd(b, a % b, y, x);
  y -= (a / b) * x;
  return gcd;
}
template <typename... T>
void debug(T&&... args) {}
const ll INFL = numeric_limits<ll>::max() / 2;
const ll INF = numeric_limits<int>::max() / 2;
const ll MOD = 1e9 + 7;
const int N = 5e5 + 5;
int t[N], a[N], b[N];
void solve() {
  int q;
  cin >> q;
  while (q--) {
    int n, m, c, c0;
    cin >> n >> m >> c >> c0;
    vector<pair<int, int>> order;
    for (int i = 0; i < n; i++) {
      cin >> t[i] >> a[i] >> b[i];
      order.push_back({t[i], i});
    }
    order.push_back({m, -1});
    sort((order).begin(), (order).end());
    ll ans = 0;
    bool fail = false;
    int last = 0, sum = c0;
    map<int, int> f;
    f[0] = c0;
    for (auto [current, idx] : order) {
      vector<int> gc;
      int dist = current - last;
      for (auto it = f.begin(); it != f.end(); it++) {
        auto& [price, have] = *it;
        int u = min(dist, have);
        debug(
            "price"
            ":",
            (price),
            "have"
            ":",
            (have));
        dist -= u;
        have -= u;
        last += u;
        sum -= u;
        ans += (ll)u * (ll)price;
        if (have == 0) gc.push_back(price);
        if (dist == 0) break;
      }
      if (dist > 0) {
        fail = true;
        break;
      }
      for (int price : gc) {
        if (f.count(price)) f.erase(price);
      }
      gc.clear();
      if (current != m) {
        sum += a[idx];
        int cost = b[idx];
        if (f.count(cost) == 0) f[cost] = 0;
        f[cost] += a[idx];
        if (sum > c) {
          int d = sum - c;
          for (auto it = f.rbegin(); it != f.rend(); it++) {
            auto& [price, have] = *it;
            int u = min(d, have);
            d -= u;
            have -= u;
            sum -= u;
            if (have == 0) gc.push_back(price);
          }
        }
      }
      for (int price : gc) {
        if (f.count(price)) f.erase(price);
      }
      gc.clear();
      debug("processed: ", current);
    }
    cout << (fail ? -1 : ans) << "\n";
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
