#include <bits/stdc++.h>
using namespace std;
template <class T>
void debug(T a, T b) {
  ;
}
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
namespace std {
template <class S, class T>
ostream& operator<<(ostream& out, const pair<S, T>& a) {
  out << '(' << a.first << ',' << a.second << ')';
  return out;
}
}  // namespace std
long long int readL() {
  long long int res;
  scanf("%I64d", &res);
  return res;
}
void printL(long long int res) { printf("%I64d", res); }
template <long long int mod>
struct Int_ {
  unsigned x;
  int mpow(Int_ a, int k) {
    Int_ res = 1;
    while (k) {
      if (k & 1) res = res * a;
      a = a * a;
      k >>= 1;
    }
    return res.x;
  }
  int inverse(Int_ a) { return mpow(a, mod - 2); }
  Int_() : x(0) {}
  Int_(long long sig) {
    int sigt = sig % mod;
    if (sigt < 0) sigt += mod;
    x = sigt;
  }
  int get() const { return (int)x; }
  Int_& operator+=(Int_ that) {
    if ((x += that.x) >= mod) x -= mod;
    return *this;
  }
  Int_& operator-=(Int_ that) {
    if ((x += mod - that.x) >= mod) x -= mod;
    return *this;
  }
  Int_& operator*=(Int_ that) {
    x = (unsigned long long)x * that.x % mod;
    return *this;
  }
  Int_& operator=(Int_ that) {
    x = that.x;
    return *this;
  }
  Int_& operator/=(Int_ that) {
    x = (unsigned long long)x * inverse(that.x) % mod;
    return *this;
  }
  bool operator==(Int_ that) const { return x == that.x; }
  bool operator!=(Int_ that) const { return x != that.x; }
  Int_ operator-() const { return Int_(0) - Int_(*this); }
  Int_ operator+(Int_ that) const { return Int_(*this) += that; }
  Int_ operator-(Int_ that) const { return Int_(*this) -= that; }
  Int_ operator*(Int_ that) const { return Int_(*this) *= that; }
  Int_ operator/(Int_ that) const { return Int_(*this) /= that; }
};
namespace std {
template <long long int mod>
ostream& operator<<(ostream& out, const Int_<mod>& a) {
  out << a.get();
  return out;
}
template <long long int mod>
istream& operator>>(istream& in, Int_<mod>& a) {
  in >> a.x;
  return in;
}
};  // namespace std
int n;
Int_<1000000007> dp[100005][2];
vector<int> g[100005];
void solve(int v, Int_<1000000007> dp2[2][3][2]) {
  for (int i = 0; i < (2); ++i)
    for (int j = 0; j < (3); ++j)
      for (int k = 0; k < (2); ++k) dp2[i][j][k] = 0;
  for (auto to : g[v]) {
    Int_<1000000007> tmp[2][3][2] = {0};
    for (int i = 0; i < (2); ++i)
      for (int j = 0; j < (3); ++j)
        for (int k = 0; k < (2); ++k)
          for (int i2 = 0; i2 < (2); ++i2)
            tmp[i ^ i2][j == i2 ? j : 2][k ^ 1] += dp[to][i2] * dp2[i][j][k];
    for (int i = 0; i < (2); ++i)
      for (int j = 0; j < (3); ++j)
        for (int k = 0; k < (2); ++k) dp2[i][j][k] += tmp[i][j][k];
    dp2[0][1][1] += dp[to][1];
    dp2[1][0][1] += dp[to][0];
  }
}
void rec(int v) {
  for (auto to : g[v]) rec(to);
  Int_<1000000007> dp2[2][3][2];
  solve(v, dp2);
  dp[v][0] += dp2[0][2][0] + dp2[0][2][1] + dp2[0][1][0];
  dp[v][1] += dp2[1][2][0] + dp2[1][2][1] + dp2[1][1][0];
  reverse((g[v]).begin(), (g[v]).end());
  solve(v, dp2);
  for (int i = 0; i < (2); ++i)
    for (int j = 0; j < (3); ++j)
      for (int k = 0; k < (2); ++k) dp[v][i] += dp2[i][j][k];
  dp[v][1] += 1;
}
int main() {
  cin >> n;
  for (int i = 0; i < (n - 1); ++i) {
    int p;
    scanf("%d", &p);
    --p;
    g[p].push_back(i + 1);
  }
  rec(0);
  cout << dp[0][0] + dp[0][1] << endl;
  return 0;
}
