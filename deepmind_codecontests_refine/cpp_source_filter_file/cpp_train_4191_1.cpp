#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<long long>;
template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T>
istream &operator>>(istream &, vector<T> &);
template <class T>
ostream &operator<<(ostream &, const vector<T> &);
template <class T, class U>
istream &operator>>(istream &, pair<T, U> &);
template <class T, class U>
ostream &operator<<(ostream &, const pair<T, U> &);
template <class T>
struct Inf {
  static constexpr T inf() {
    return std::numeric_limits<T>::has_infinity
               ? std::numeric_limits<T>::infinity()
               : std::numeric_limits<T>::max();
  }
};
template <>
struct Inf<int> {
  static constexpr int inf() { return 0x3f3f3f3f; }
};
template <>
struct Inf<long long> {
  static constexpr long long inf() { return 0x3f3f3f3f3f3f3f3fLL; }
};
constexpr int INF = Inf<int>::inf();
constexpr ll BINF = Inf<ll>::inf();
int solve() {
  int n, k;
  cin >> n >> k;
  using pll = pair<ll, ll>;
  using vpll = vector<pll>;
  vpii ab(n);
  cin >> ab;
  vpll dp(k, pll(-BINF, 0));
  vpll lst(dp);
  lst[0] = pll(0, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      for (int dj = 0; dj < k; dj++) {
        if (dj > ab[i].first) continue;
        auto [cans, cb] = lst[(j + k - dj) % k];
        if (cans < 0) continue;
        if (j - dj < 0) cans++;
        int rema = ab[i].first - dj;
        cans += rema / k;
        rema %= k;
        int needb = k - rema;
        if (ab[i].second >= needb) {
          cans++;
          cb -= needb;
        }
        cb += ab[i].second;
        cans += cb / k;
        cb %= k;
        dp[j] = max(dp[j], pll(cans, cb));
      }
    }
    lst.swap(dp);
  }
  ll ans = 0;
  for (auto [l, r] : dp) ans = max(l, ans);
  cout << ans << endl;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) is >> *it;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto it = v.begin(); it != v.end();)
    os << *it, os << " \n"[++it == v.end()];
  return os;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << ' ' << p.second;
}
