#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 998244353;
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
          ret.a[i * m.w + j] += a[i * w + k] * m.a[k * m.w + j] % mod;
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
  for (int i = (int)(0); i < (int)(n); ++i) ret.get(i, i) = 1;
  return ret;
}
Matrix<ll> P[40];
void mult(vector<ll>& v, Matrix<ll>& A) {
  int m = v.size();
  vector<ll> nv(m);
  for (int i = (int)(0); i < (int)(m); ++i)
    for (int j = (int)(0); j < (int)(m); ++j) {
      nv[i] += A.get(i, j) * v[j] % mod;
    }
  for (int i = (int)(0); i < (int)(m); ++i) nv[i] %= mod;
  v.swap(nv);
}
void calc(vector<ll>& v, int n) {
  int m = v.size();
  int idx = 0;
  while (n) {
    if (n & 1) {
      vector<ll> nv(m);
      for (int i = (int)(0); i < (int)(m); ++i)
        for (int j = (int)(0); j < (int)(m); ++j) {
          nv[i] += P[idx].get(i, j) * v[j] % mod;
        }
      for (int i = (int)(0); i < (int)(m); ++i) nv[i] %= mod;
      v.swap(nv);
    }
    n >>= 1;
    ++idx;
  }
}
ll dp[1010][4];
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = (int)(0); i < (int)(n); ++i) cin >> a[i];
  int m;
  cin >> m;
  vector<pair<int, int>> v[n];
  for (int i = (int)(0); i < (int)(m); ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    --x;
    --z;
    v[x].emplace_back(y, z);
  }
  int f[3][3];
  for (int i = (int)(0); i < (int)(3); ++i)
    for (int j = (int)(0); j < (int)(3); ++j) cin >> f[i][j];
  P[0] = Matrix<ll>(64, 64);
  for (int i = (int)(0); i < (int)(4); ++i)
    for (int j = (int)(0); j < (int)(4); ++j)
      for (int k = (int)(0); k < (int)(4); ++k) {
        int cur = 16 * i + 4 * j + k;
        for (int idx = (int)(0); idx < (int)(3); ++idx) {
          vector<int> ok(4);
          if (f[idx][0]) ok[i] = 1;
          if (f[idx][1]) ok[j] = 1;
          if (f[idx][2]) ok[k] = 1;
          int nxt = 0;
          while (ok[nxt]) ++nxt;
          P[0].get(16 * nxt + 4 * i + j, cur) += 1;
        }
      }
  Matrix<ll> A[3];
  for (int i = (int)(0); i < (int)(3); ++i) A[i] = Matrix<ll>(64, 64);
  for (int i = (int)(0); i < (int)(4); ++i)
    for (int j = (int)(0); j < (int)(4); ++j)
      for (int k = (int)(0); k < (int)(4); ++k) {
        int cur = 16 * i + 4 * j + k;
        for (int idx = (int)(0); idx < (int)(3); ++idx) {
          vector<int> ok(4);
          if (f[idx][0]) ok[i] = 1;
          if (f[idx][1]) ok[j] = 1;
          if (f[idx][2]) ok[k] = 1;
          int nxt = 0;
          while (ok[nxt]) ++nxt;
          A[idx].get(16 * nxt + 4 * i + j, cur) += 1;
        }
      }
  for (int i = (int)(0); i < (int)(35); ++i) {
    P[i + 1] = P[i] * P[i];
  }
  for (int i = (int)(0); i < (int)(n); ++i) {
    vector<ll> res(64);
    res[63] = 1;
    int cur = 0;
    sort(v[i].begin(), v[i].end());
    for (auto p : v[i]) {
      calc(res, p.first - cur - 1);
      mult(res, A[p.second]);
      cur = p.first;
    }
    calc(res, a[i] - cur);
    for (int j = (int)(0); j < (int)(64); ++j) (dp[i][j / 16] += res[j]) %= mod;
  }
  vector<ll> ans(4);
  ans[0] = 1;
  for (int k = (int)(0); k < (int)(n); ++k) {
    vector<ll> na(4);
    for (int i = (int)(0); i < (int)(4); ++i)
      for (int j = (int)(0); j < (int)(4); ++j) {
        na[i ^ j] += ans[i] * dp[k][j] % mod;
      }
    for (int i = (int)(0); i < (int)(4); ++i) na[i] %= mod;
    ans.swap(na);
  }
  cout << ans[0] << endl;
  return 0;
}
