#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vec<T>>;
template <class T>
bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
constexpr ll mod = 998244353;
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
  bool operator==(const mint a) const { return x == a.x; }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vec<int> A(N + 1);
  for (int i = 1; i <= N; i++) cin >> A[i];
  sort((A).begin(), (A).end());
  vec<int> cnt(N + 1);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j < i; j++)
      if (2 * A[j] <= A[i]) cnt[i]++;
  vec<mint> sum(N + 1, 1);
  vvec<mint> dp(N + 1, vec<mint>(N + 1, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= N; j++) {
      if (cnt[j] - i + 1 >= 0)
        dp[i + 1][j] += dp[i][j] * (cnt[j] - i + 1);
      else
        dp[i + 1][j] = 0;
      dp[i + 1][j] += sum[cnt[j] + 1];
    }
    sum[0] = 0;
    for (int j = 0; j < N; j++) sum[j + 1] = sum[j] + dp[i + 1][j];
  }
  cout << dp[N][N] << "\n";
}
