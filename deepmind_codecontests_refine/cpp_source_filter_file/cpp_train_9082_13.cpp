#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (ll)1e18;
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
constexpr ll dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr ll dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};
void p() { std::cout << '\n'; }
template <typename Head, typename... Tail>
void p(Head head, Tail... tail) {
  std::cout << head << (sizeof...(tail) ? " " : "");
  p(tail...);
}
template <typename T>
inline void pv(std::vector<T>& v) {
  for (ll i = 0, N = v.size(); i < N; i++)
    std::cout << v[i] << " \n"[i == N - 1];
}
template <typename T>
inline bool chmax(T& a, T b) {
  return a < b && (a = b, true);
}
template <typename T>
inline bool chmin(T& a, T b) {
  return a > b && (a = b, true);
}
template <typename T>
inline void uniq(std::vector<T>& v) {
  v.erase(std::unique(v.begin(), v.end()), v.end());
}
void solve() {
  ll L, R, M;
  cin >> L >> R >> M;
  for (ll a = L; a <= R; a++) {
    ll t = M / a;
    ll s = M - t * a;
    if (t > 0 && s <= (R - L)) {
      p(a, L + s, L);
      return;
    }
    t++;
    s = M - t * a;
    if (abs(s) <= (R - L)) {
      p(a, R, R - s);
      return;
    }
  }
}
signed main() {
  ll Q;
  cin >> Q;
  for (ll q = 0, q_length = (Q); q < q_length; ++q) solve();
  return 0;
}
