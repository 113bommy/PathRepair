#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);
template <class T>
T MIN(const T& a, const T& b) {
  return a < b ? a : b;
}
template <class T>
T MAX(const T& a, const T& b) {
  return a > b ? a : b;
}
template <class T>
void MIN_UPDATE(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void MAX_UPDATE(T& a, const T& b) {
  if (a < b) a = b;
}
template <long long M>
struct G {
  long long x;
  G() : x(0) {}
  G(long long x) : x(x % M) {}
  G& operator+=(const G& rh) {
    x = (x + rh.x) % M;
    return *this;
  }
  G& operator-=(const G& rh) {
    x = (x + M - rh.x) % M;
    return *this;
  }
  G& operator*=(const G& rh) {
    x = (x * rh.x) % M;
    return *this;
  }
  G& operator/=(const G& rh) { return *this *= rh.pow(M - 2); }
  G operator+(const G& rh) const { return G(*this) += rh; }
  G operator-(const G& rh) const { return G(*this) -= rh; }
  G operator*(const G& rh) const { return G(*this) *= rh; }
  G operator/(const G& rh) const { return G(*this) /= rh; }
  bool operator==(const G& rh) const { return x == rh.x; }
  bool operator!=(const G& rh) const { return x != rh.x; }
  G& operator++() { return *this += 1; }
  G pow(long long e) const {
    G y(*this), v(1);
    for (; e; y *= y, e >>= 1)
      if (e & 1) v *= y;
    return v;
  }
  G C(long long k) {
    G v = 1;
    for (long long i = 1; i <= k; ++i) {
      v *= *this - i + 1;
      v /= i;
    }
    return v;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  static G<1000000007> C[2048][2048];
  C[0][0] = 1;
  for (int n = 1; n < 2048; ++n) {
    C[n][0] = 1;
    for (int r = 1; r < 2048; ++r) {
      C[n][r] = C[n - 1][r - 1] + C[n - 1][r];
    }
  }
  static G<1000000007> factorial[2048];
  factorial[0] = 1;
  for (int i = 1; i < 2048; ++i) {
    factorial[i] = factorial[i - 1] * i;
  }
  static bool used[2048];
  static int a[2048];
  int n;
  cin >> n;
  int numberOfRemain = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    used[a[i]] = true;
    if (a[i] < 0) {
      ++numberOfRemain;
    }
  }
  int numberOfFixedPointCandidates = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] < 0 && !used[i]) {
      ++numberOfFixedPointCandidates;
    }
  }
  G<1000000007> answer = 0;
  int sign = 1;
  for (int numberOfFixedPoints = 0;
       numberOfFixedPoints <= numberOfFixedPointCandidates;
       ++numberOfFixedPoints) {
    answer += C[numberOfFixedPointCandidates][numberOfFixedPoints] *
              factorial[numberOfRemain - numberOfFixedPoints] * sign;
    sign = -sign;
  }
  cout << answer.x << endl;
}
