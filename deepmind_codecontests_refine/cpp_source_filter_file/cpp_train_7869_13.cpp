#include <bits/stdc++.h>
static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;
template <class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;
template <u32 M = 1000000007>
struct modint {
  u32 val;
  modint() : val(0) {}
  template <typename T>
  modint(T t) {
    t %= (T)M;
    if (t < 0) t += (T)M;
    val = t;
  }
  modint pow(ll k) const {
    modint res(1), x(val);
    while (k) {
      if (k & 1) res *= x;
      x *= x;
      k >>= 1;
    }
    return res;
  }
  template <typename T>
  modint& operator=(T t) {
    t %= (T)M;
    if (t < 0) t += (T)M;
    val = t;
    return *this;
  }
  modint inv() const { return pow(M - 2); }
  modint& operator+=(modint a) {
    val += a.val;
    if (val >= M) val -= M;
    return *this;
  }
  modint& operator-=(modint a) {
    if (val < a.val)
      val += M - a.val;
    else
      val -= a.val;
    return *this;
  }
  modint& operator*=(modint a) {
    val = (u64)val * a.val % M;
    return *this;
  }
  modint& operator/=(modint a) { return (*this) *= a.inv(); }
  modint operator+(modint a) const { return modint(val) += a; }
  modint operator-(modint a) const { return modint(val) -= a; }
  modint operator*(modint a) const { return modint(val) *= a; }
  modint operator/(modint a) const { return modint(val) /= a; }
  modint operator-() { return modint(M - val); }
  bool operator==(const modint a) const { return val == a.val; }
  bool operator!=(const modint a) const { return val != a.val; }
  bool operator<(const modint a) const { return val < a.val; }
};
using mint = modint<MOD>;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) {
      v[i][j] = s[j] - 'a';
    }
  }
  int q;
  cin >> q;
  v.resize(n + q, vector<int>(m, 0));
  for (int i = 0; i < q; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) {
      v[n + i][j] = s[j] - 'a';
    }
  }
  vector<int> inv = {0, 1, 3, 2, 4};
  int rank = 0;
  for (int c = 0; c < m; ++c) {
    int k = -1;
    for (int i = rank; i < n; ++i) {
      if (v[i][c]) {
        k = i;
        break;
      }
    }
    if (!~k) continue;
    swap(v[k], v[rank]);
    int x = inv[v[rank][c]];
    for (int j = 0; j < m; ++j) v[rank][j] = (v[rank][j] * x) % 5;
    for (int i = 0; i < n + q; ++i) {
      if (i != rank && v[i][c]) {
        int coeff = v[i][c];
        for (int j = 0; j < m; ++j) {
          v[i][j] -= v[rank][j] * coeff % 5;
          if (v[i][j] < 0) v[i][j] += 5;
        }
      }
    }
    rank++;
  }
  int ans = mint(5).pow(n - rank).val;
  for (int i = 0; i < q; ++i) {
    int ok = 1;
    for (int j = rank; j < m; ++j) {
      if (v[n + i][j]) ok = 0;
    }
    printf("%d\n", ok ? ans : 0);
  }
  return 0;
}
