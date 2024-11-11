#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long longinf = 1LL << 60;
const long long mod = 1e9 + 7;
template <typename T>
struct Matrix {
  int h, w;
  vector<T> a;
  Matrix(int n_ = 0) : h(n_), w(n_), a(n_ * n_) {}
  Matrix(int n_, int m_) : h(n_), w(m_), a(n_ * m_) {}
  Matrix(int n_, int m_, vector<T> a_) : h(n_), w(m_), a(a_) {}
  T& get(int r, int c) { return a[r * w + c]; }
  T get(int r, int c) const { return a[r * w + c]; }
  Matrix& operator+=(const Matrix& m) {
    assert(h == m.h && w == m.w);
    for (int i = 0; i < w * h; ++i) a[i] += m.a[i];
  }
  Matrix& operator-=(const Matrix& m) {
    assert(h == m.h && w == m.w);
    for (int i = 0; i < w * h; ++i) a[i] -= m.a[i];
  }
  Matrix& operator*=(const Matrix& m) {
    assert(w == m.h);
    Matrix ret(h, m.w);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < m.w; ++j) {
        for (int k = 0; k < w; ++k) {
          ret.a[i * m.w + j] += a[i * w + k] * m.a[k * m.w + j];
        }
        ret.a[i * m.w + j] %= mod;
      }
    }
    return (*this) = ret;
  }
  Matrix operator+(const Matrix& m) const { return Matrix(*this) += m; }
  Matrix operator-(const Matrix& m) const { return Matrix(*this) -= m; }
  Matrix operator*(const Matrix& m) const { return Matrix(*this) *= m; }
};
template <typename T>
Matrix<T> unit(int n) {
  Matrix<T> ret(n);
  for (int i = (int)0; i < (int)n; ++i) ret.get(i, i) = 1;
  return ret;
}
template <typename T>
Matrix<T> matpow(Matrix<T> a, int n) {
  assert(a.h == a.w);
  Matrix<T> ret = unit<T>(a.h);
  while (n) {
    if (n & 1) ret *= a;
    a *= a;
    n >>= 1;
  }
  return ret;
}
int main() {
  int n, b, x, k;
  cin >> n >> b >> k >> x;
  vector<int> cnt(10);
  for (int i = (int)0; i < (int)n; ++i) {
    int a;
    cin >> a;
    ++cnt[a];
  }
  Matrix<long long> A(x);
  for (int i = (int)0; i < (int)x; ++i) {
    for (int j = (int)0; j < (int)10; ++j) {
      A.get(i, (10 * i + j) % x) += cnt[j];
    }
  }
  Matrix<long long> ret = matpow(A, b);
  cout << ret.get(0, k) << endl;
  return 0;
}
