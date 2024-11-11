#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
inline bool mina(A &first, B second) {
  return (first > second) ? (first = second, 1) : 0;
}
template <class A, class B>
inline bool maxa(A &first, B second) {
  return (first < second) ? (first = second, 1) : 0;
}
template <typename Int, Int mod>
class ModInt {
 public:
  static const Int Mod = mod;
  Int first;
  ModInt() { first = 0; }
  ModInt(int a) {
    Int t = a % mod;
    if (t < 0) t += mod;
    first = t;
  }
  ModInt(long long a) {
    Int t = a % mod;
    if (t < 0) t += mod;
    first = t;
  }
  Int get() const { return first; }
  ModInt &operator+=(ModInt that) {
    if ((first += that.first) >= mod) first -= mod;
    return *this;
  }
  ModInt &operator-=(ModInt that) {
    if ((first += mod - that.first) >= mod) first -= mod;
    return *this;
  }
  ModInt &operator*=(ModInt that) {
    first = (long long)(first)*that.first % mod;
    return *this;
  }
  bool operator==(ModInt that) const { return first == that.first; }
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator-() const { return ModInt(-this->first); }
  inline friend ostream &operator<<(ostream &out, ModInt m) {
    return out << m.first;
  }
  ModInt power(long long k) const {
    ModInt r(1);
    ModInt b = *this;
    if (k <= 0) return r;
    while (k) {
      if (k & 1) r *= b;
      b *= b;
      k >>= 1;
    }
    return r;
  }
  ModInt inverse() const {
    long long a = first, b = mod, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return ModInt(u);
  }
};
const int MAXN = 2005;
int N, H;
int in[MAXN];
ModInt<int, (1000000007)> dp[MAXN][MAXN / 2];
int main() {
  scanf("%d %d", &N, &H);
  for (int i = 0; (i) < (N); ++(i)) {
    scanf("%d", &in[i]);
  }
  if (in[0] == H) {
    dp[0][0] = 1;
  } else if (in[0] + 1 == H) {
    dp[0][1] = 1;
    dp[0][0] = 1;
  } else {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i < N; i++) {
    int diff = H - in[i];
    if (diff < 0 || diff >= MAXN / 2) {
      cout << 0 << endl;
      return 0;
    } else if (diff == 0) {
      dp[i][0] += dp[i - 1][0];
    } else {
      dp[i][diff - 1] += dp[i - 1][diff] * diff;
      dp[i][diff] += dp[i - 1][diff - 1];
      dp[i][diff - 1] += dp[i - 1][diff - 1] * diff;
      dp[i][diff] += dp[i - 1][diff];
    }
  }
  cout << dp[N - 1][0] << endl;
  return 0;
}
