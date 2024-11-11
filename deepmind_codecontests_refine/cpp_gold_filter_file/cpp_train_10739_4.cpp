#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long __64inf = 0x3f3f3f3f3f3f3f3f;
const int MAX = 87000;
const int Mod = 998244353;
template <class T>
struct F {
  T x;
  F(T x = 0) : x(x) {}
  inline F &operator+=(const F &other) {
    x = (x + other.x) % Mod;
    if (x < 0) x += Mod;
    return *this;
  }
  inline F &operator*=(const F &other) {
    x = (x * other.x) % Mod;
    if (x < 0) x += Mod;
    return *this;
  }
  inline F operator*(const F &other) const {
    T xx = x * other.x % Mod;
    if (xx < 0) xx += Mod;
    return F(xx);
  }
};
template <class T>
ostream &operator<<(ostream &out, const F<T> &x) {
  cout << x.x;
  return out;
}
template <class T>
F<T> operator*(long long a, const F<T> &b) {
  return F<T>((a * b.x) % Mod);
}
template <class T>
F<T> operator+(long long a, const F<T> &b) {
  return F<T>((a + b.x) % Mod);
}
F<long long> dp[505][505];
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> col(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> col[i];
  }
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      if (i >= j) dp[i][j] = 1;
    }
  }
  for (int L = 1; L < n; L++) {
    for (int i = 1; i + L <= n; i++) {
      pair<int, int> lo = {col[i], i};
      for (int j = i; j <= L + i; j++) lo = min(lo, {col[j], j});
      int pos = lo.second;
      F<long long> cnt1, cnt2;
      for (int a = i; a <= pos; a++) {
        cnt1 += dp[i][a - 1] * dp[a][pos - 1];
      }
      for (int b = pos; b <= i + L; b++) {
        cnt2 += dp[pos + 1][b] * dp[b + 1][i + L];
      }
      dp[i][i + L] = cnt1 * cnt2;
    }
  }
  cout << dp[1][n] << endl;
  return 0;
}
