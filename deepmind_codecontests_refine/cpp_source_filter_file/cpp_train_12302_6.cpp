#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U>
using Pa = pair<T, U>;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vec<T>>;
constexpr ll mod = 1e9 + 7;
struct mint {
  ll x;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  friend ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
  friend istream& operator>>(istream& is, mint& a) {
    ll t;
    is >> t;
    a = mint(t);
    return (is);
  }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vec<ll> L(N), R(N);
  vec<mint> P(N), P2(N);
  for (int i = 0; i < N; i++) cin >> L[i];
  for (int i = 0; i < N; i++) {
    cin >> R[i];
    P[i] = R[i] - L[i] + 1;
    P[i] = P[i].inv();
  }
  mint ans = N * N;
  mint E = 0;
  for (int i = 0; i < N - 1; i++) {
    ll l = max(L[i], L[i + 1]), r = min(R[i], R[i + 1]);
    ll len = max(r - l + 1, 0LL);
    P2[i] = P[i] * P[i + 1] * len;
    E += P2[i];
  }
  ans += E * (-2 * N + 1);
  mint E2 = 0;
  vec<mint> S(N + 1, 0);
  for (int i = N - 2; i >= 0; i--) S[i] = S[i + 1] + P2[i];
  for (int i = 0; i + 2 <= N - 2; i++) E2 += P2[i] * S[i + 2];
  for (int i = 1; i + 1 < N; i++) {
    ll l = max({L[i - 1], L[i], L[i + 1]}), r = min({R[i - 1], R[i], R[i + 1]});
    if (r < l) continue;
    E2 += P[i - 1] * P[i] * P[i + 1] * (r - l + 1);
  }
  ans += E2 * 2;
  cout << ans << "\n";
}
