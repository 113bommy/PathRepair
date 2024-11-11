#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const int SIZE = 1000002;
const long long INF = 1LL << 30;
const double eps = 1e-4;
const double PI = 3.1415926535897932;
struct ModInt {
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) : x(sig % MOD) {}
  ModInt(signed long long sig) : x(sig % MOD) {}
  int get() const { return (int)x; }
  ModInt pow(long long p) {
    ModInt res = 1, a = *this;
    while (p) {
      if (p & 1) res *= a;
      a *= a;
      p >>= 1;
    }
    return res;
  }
  ModInt &operator+=(ModInt that) {
    if ((x += that.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator-=(ModInt that) {
    if ((x += MOD - that.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator*=(ModInt that) {
    x = (unsigned long long)x * that.x % MOD;
    return *this;
  }
  ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MOD - 2); }
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator<(ModInt that) const { return x < that.x; }
  friend ostream &operator<<(ostream &os, ModInt a) {
    os << a.x;
    return os;
  }
};
ModInt a[15];
ModInt adj[15][15];
ModInt p[16384];
ModInt h[14][16384];
int n;
ModInt g(int x, int y) {
  ModInt ans = 1;
  for (int i = 0; i < (n); ++i) {
    if (x >> i & 1) {
      for (int j = 0; j < (n); ++j) {
        if (y >> j & 1) {
          ans *= h[i][j];
        }
      }
    }
  }
  return ans;
}
int main() {
  scanf("%d", &(n));
  for (int i = 0; i < (n); ++i) {
    int xx;
    scanf("%d", &xx);
    a[i] = xx;
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (n); ++j) {
      if (i == j) continue;
      adj[i][j] = a[i] / (a[i] + a[j]);
    }
  }
  int bmax = 1 << n;
  for (int i = 0; i < (n); ++i) {
    for (int bm = 0; bm < (bmax); ++bm) {
      h[i][bm] = 1;
      for (int bi = 0; bi < (n); ++bi) {
        if (bm >> bi & 1) {
          h[i][bm] *= adj[i][bi];
        }
      }
    }
  }
  p[0] = 1;
  for (int bm = (1); bm < (bmax); ++bm) {
    p[bm] = 1;
    for (int bm2 = bm; bm2; bm2 = (bm2 - 1) & bm) {
      if (bm2 == bm) continue;
      p[bm] -= p[bm2] * g(bm2, bm ^ bm2);
      if (bm2 == 0) break;
    }
  }
  ModInt ans = 0;
  for (int bm = (1); bm < (bmax); ++bm) {
    ModInt f = p[bm] * g(bm, (bmax - 1) ^ bm);
    ans += f * __builtin_popcountll(bm);
  }
  printf("%u", ans.x);
}
