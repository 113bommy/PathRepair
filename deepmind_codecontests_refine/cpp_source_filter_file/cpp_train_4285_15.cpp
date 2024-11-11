#include <bits/stdc++.h>
using namespace std;
struct Matrix {
  int h, w;
  vector<long long> mat;
  Matrix() { h = w = 0; }
  Matrix(int h, int w) {
    this->h = h, this->w = w;
    mat.resize(h * w);
  }
  long long& at(int i, int j) { return mat[w * (i - 1) + (j - 1)]; }
  static Matrix ident(int size) {
    Matrix ret(size, size);
    for (int i = 1; i <= size; i++) ret.at(i, i) = 1;
    return ret;
  }
  Matrix operator*(Matrix& ope) {
    Matrix ret(h, ope.w);
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= ope.w; j++) {
        for (int k = 1; k <= w; k++) {
          ret.at(i, j) += at(i, k) * ope.at(k, j) % 1000000007;
          ret.at(i, j) %= 1000000007;
        }
      }
    }
    return ret;
  }
  Matrix pow(long long n) {
    if (n == 0) return ident(h);
    if (n % 2) {
      return pow(n - 1) * (*this);
    } else {
      Matrix tmp = pow(n / 2);
      return tmp * tmp;
    }
  }
  void print() {
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cout << at(i, j) << " ";
      }
      cout << endl;
    }
  }
};
long long modpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2) {
    return ((a % 1000000007) * (modpow(a, n - 1) % 1000000007)) % 1000000007;
  } else {
    return modpow((a * a) % 1000000007, n / 2) % 1000000007;
  }
}
long long n, k;
long long a[105];
int main(void) {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int cnt = 0, cor = 0;
  for (int i = 1; i <= n; i++)
    if (a[i]) cnt++;
  for (int i = n - cnt + 1; i <= n; i++)
    if (a[i]) cor++;
  Matrix mat(cnt + 1, cnt + 1);
  long long bunbo = modpow(n * (n - 1) / 2, 1000000007 - 2);
  for (int i = 0; i <= cnt; i++) {
    for (int j = 0; j <= cnt; j++) {
      mat.at(i + 1, j + 1) = 0;
    }
  }
  for (int i = 0; i <= cnt; i++) {
    long long a = (cnt - i) * (cnt - i) % 1000000007,
              b = i * (n + i - 2 * cnt) % 1000000007;
    if (i - 1 >= 1) mat.at(i, i + 1) = b * bunbo % 1000000007;
    if (i + 1 <= cnt) mat.at(i + 2, i + 1) = a * bunbo % 1000000007;
    mat.at(i + 1, i + 1) = (n * (n - 1) / 2 - (a + b) + 2 * 1000000007) %
                           1000000007 * bunbo % 1000000007;
  }
  cout << mat.pow(k).at(cnt + 1, cor + 1) << endl;
  return 0;
}
