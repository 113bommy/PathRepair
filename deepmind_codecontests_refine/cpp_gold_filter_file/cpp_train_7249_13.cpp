#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
const int _N = 256, _M = 256;
template <class V>
struct Matrix {
  int n, m;
  V x[_N][_M];
  Matrix &operator=(const V &t) {
    for (int i = (0); i <= (n - 1); ++i)
      for (int j = (0); j <= (m - 1); ++j) x[i][j] = t;
    return *this;
  }
  void set(int _n, int _m, V x = 0) { n = _n, m = _m, *this = x; }
  Matrix(int _n = 0, int _m = 0, V x = 0) { n = _n, m = _m, *this = x; }
  V *operator[](const int &t) { return x[t]; }
  Matrix &operator+=(const Matrix &t) {
    for (int i = (0); i <= (n - 1); ++i)
      for (int j = (0); j <= (m - 1); ++j) x[i][j] += t.x[i][j];
    return *this;
  }
  Matrix &operator*=(const Matrix &t) {
    Matrix C(n, t.m, ooo);
    for (int i = (0); i <= (n - 1); ++i)
      for (int k = (0); k <= (m - 1); ++k)
        if (x[i][k] != ooo)
          for (int j = (0); j <= (t.m - 1); ++j)
            if (t.x[k][j] != ooo)
              C[i][j] =
                  ((C[i][j]) < (x[i][k] + t.x[k][j]) ? (C[i][j])
                                                     : (x[i][k] + t.x[k][j]));
    return *this = C;
  }
  Matrix &operator*=(const V &t) {
    for (int i = (0); i <= (n - 1); ++i)
      for (int j = (0); j <= (m - 1); ++j) x[i][j] *= t;
    return *this;
  }
  friend Matrix operator+(const Matrix &A, const Matrix &B) {
    Matrix C = A;
    C += B;
    return C;
  }
  friend Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix C = A;
    C *= B;
    return C;
  }
  friend Matrix operator*(const Matrix &A, const V &B) {
    Matrix C = A;
    C *= B;
    return C;
  }
  friend Matrix operator*(const V &A, const Matrix &B) {
    Matrix C = B;
    C *= A;
    return C;
  }
  static Matrix E(int n) {
    Matrix C(n, n, 0);
    for (int i = (0); i <= (n - 1); ++i) C.x[i][i] = 1;
    return C;
  }
};
void pre_calc(Matrix<long long> *F, long long k) {
  for (int i = 1; (1 << i) <= k; i++) F[i] = F[i - 1] * F[i - 1];
}
Matrix<long long> Pow(Matrix<long long> *F, long long k) {
  int t = F[0].n;
  Matrix<long long> ans(t, t);
  ans = Matrix<long long>::E(t);
  for (int i = 0; k; k >>= 1, i++)
    if (k & 1) ans *= F[i];
  return ans;
}
struct D {
  int x;
  long long c;
};
bool cmp(const D &a, const D &b) { return a.x < b.x; }
int x, k, n, q, cnt, now = 1;
D d[30];
long long c[12];
Matrix<long long> F[35], ans, T;
map<int, long long> M;
int main() {
  scanf("%d%d%d%d", &x, &k, &n, &q), cnt = 1 << k;
  F[0].set(cnt, cnt, ooo), ans.set(1, cnt, ooo), ans[0][(1 << x) - 1] = 0;
  for (int i = (1); i <= (k); ++i) scanf("%I64d", &c[i]);
  for (int i = (0); i <= (cnt - 1); ++i)
    if (i & 1) {
      for (int j = (1); j <= (k); ++j)
        if (!(i >> j & 1)) F[0][i][(i | 1 << j) >> 1] = c[j];
    } else
      F[0][i][i >> 1] = 0;
  pre_calc(F, n);
  for (int i = (1); i <= (q); ++i)
    scanf("%d%I64d", &d[i].x, &d[i].c), M[d[i].x] = d[i].c;
  sort(d + 1, d + q + 1, cmp);
  for (int i = (1); i <= (q); ++i) {
    if (now < d[i].x - k) {
      for (int p = d[i].x - k - now, t = 0; p; p >>= 1, t++)
        if (p & 1) ans *= F[t];
      now = d[i].x - k;
    }
    while (now < d[i].x && now < n - x + 1) {
      T = F[0];
      for (int t = (0); t <= (cnt - 1); ++t)
        if (t & 1)
          for (int j = (1); j <= (k); ++j)
            if (!(t >> j & 1)) T[t][(t | 1 << j) >> 1] += M[now + j];
      ans *= T, now++;
    }
  }
  if (now < n - x + 1)
    for (int p = n - x + 1 - now, i = 0; p; p >>= 1, i++)
      if (p & 1) ans *= F[i];
  printf("%I64d\n", ans[0][(1 << x) - 1]);
  return 0;
}
