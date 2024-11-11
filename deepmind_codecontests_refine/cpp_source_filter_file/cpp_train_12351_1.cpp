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
  unsigned mpow(Int_ a, unsigned k) {
    Int_ res = 1;
    while (k) {
      if (k & 1) res = res * a;
      a = a * a;
      k >>= 1;
    }
    return res.x;
  }
  unsigned inverse(Int_ a) { return mpow(a, mod - 2); }
  Int_() : x(0) {}
  Int_(long long sig) {
    int sigt = sig % mod;
    if (sigt < 0) sigt += mod;
    x = sigt;
  }
  unsigned get() const { return (unsigned)x; }
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
  Int_ inv() { return Int_(mpow(x, mod - 2)); }
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
Int_<998244353> mpow(Int_<998244353> a, long long int k) {
  Int_<998244353> res = 1;
  while (k) {
    if (k & 1) res = res * a;
    a = a * a;
    k >>= 1;
  }
  return res;
}
Int_<998244353> dp[2005][2005];
Int_<998244353> dp2[2005];
Int_<998244353> dp3[2005][2005];
Int_<998244353> dp4[2005];
int n;
int a, b;
Int_<998244353> pwX[4000000], pwY[4000000];
void showfrac(int a, int b) {
  Int_<998244353> sample = a;
  sample /= b;
  ;
  ;
}
int main() {
  cin >> n >> a >> b;
  Int_<998244353> X = a;
  X /= b;
  Int_<998244353> Y = -X + 1;
  ;
  ;
  ;
  ;
  pwX[0] = pwY[0] = 1;
  for (int i = 0; i < (n * n + 1); ++i) {
    pwX[i + 1] = pwX[i] * X;
    pwY[i + 1] = pwY[i] * Y;
  }
  dp3[1][0] = 1;
  dp3[1][1] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp3[i + 1][j + 1] += dp3[i][j] * pwX[(i - j)];
      dp3[i + 1][j] += dp3[i][j] * pwY[j];
    }
  }
  dp2[1] = 0;
  for (int i = 2; i <= n; ++i) {
    for (int j = (1); j < (i); ++j) dp[i][j] = dp3[i][j];
    for (int j = (1); j < (i); ++j) {
      Int_<998244353> T = dp4[j];
      dp[i][j] -= dp[i][j] * T;
    }
    Int_<998244353> tot = 0;
    for (int j = (1); j < (i); ++j) {
      tot += dp[i][j];
    }
    dp4[i] = tot;
    for (int j = (1); j < (i); ++j) {
      dp2[i] += dp[i][j] * ((dp2[i - j] - (i - j) * (i - j - 1) / 2) + dp2[j]);
    }
    dp2[i] += i * (i - 1) / 2;
    dp2[i] /= tot;
  }
  cout << dp2[n] << endl;
  return 0;
}
