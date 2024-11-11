#include <bits/stdc++.h>
using namespace std;
namespace RA {
int rnd(int p) { return 1ll * rand() * rand() % p; }
int rnd(int L, int R) { return rnd(R - L + 1) + L; }
}  // namespace RA
const int N = 1e5 + 5, K = 13, S = 1 << 5, P = 1e9 + 7;
void add(int& x, long long y) { x = (x + y) % P; }
template <const int SZ>
struct Matrix {
  int n, m, c[SZ][SZ];
  Matrix() {}
  Matrix(int _n, int _m) {
    assert(0 <= _n && _n < SZ);
    assert(0 <= _m && _m < SZ);
    n = _n, m = _m;
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (m); ++j) c[i][j] = 0;
  }
  int* operator[](int x) {
    assert(0 <= x && x < SZ);
    return c[x];
  }
  Matrix operator*(Matrix M) {
    assert(m == M.n);
    Matrix res(n, M.m);
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (m); ++j)
        if (c[i][j])
          for (int k = (1); k <= (M.m); ++k) {
            add(res[i][k], 1ll * c[i][j] * M[j][k]);
          }
    return res;
  }
};
Matrix<K * S + 1> mtx(K*S - 1, K*S - 1), a(K*S - 1, K*S - 1);
int n, k, m, lim;
int _(int j, int s) { return j * lim + s + 1; }
void addTrans(int j1, int s1, int j2, int s2, int coef) {
  add(mtx[_(j1, s1)][_(j2, s2)], coef);
}
int f[K][S], g[K][S];
int main() {
  scanf("%d%d%d", &n, &k, &m);
  f[0][0] = 1;
  lim = 1 << m;
  for (int j = (0); j <= (k); ++j)
    for (int s = (0); s <= (lim - 1); ++s) {
      addTrans(j, s, j, (s << 1) & (lim - 1), 1);
      if (j < k) {
        addTrans(j, s, j + 1, (s << 1 | 1) & (lim - 1),
                 __builtin_popcount(s) + 1);
      }
    }
  for (int i = (1); i <= (K * S - 1); ++i) a[i][i] = 1;
  while (n) {
    if (n & 1) a = a * mtx;
    mtx = mtx * mtx;
    n >>= 1;
  }
  int ans = 0;
  for (int s = (0); s <= (lim - 1); ++s) add(ans, a[_(0, 0)][_(k, s)]);
  printf("%d\n", ans);
  return 0;
}
