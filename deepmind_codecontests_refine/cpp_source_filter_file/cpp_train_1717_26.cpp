#include <bits/stdc++.h>
using namespace std;
const int MAXM = 2;
int m;
template <class T>
class Matrix {
 public:
  T data[MAXM][MAXM];
  Matrix() { memset(data, 0, sizeof(data)); }
  Matrix operator*(const Matrix& a) {
    Matrix ret;
    int i, j, k;
    for (i = 0; i < MAXM; i++) {
      for (j = 0; j < MAXM; j++) {
        if (data[i][j] != 0) {
          for (k = 0; k < MAXM; k++) {
            ret.data[i][k] += data[i][j] * a.data[j][k] % m;
            ret.data[i][k] %= m;
          }
        }
      }
    }
    return ret;
  }
  Matrix operator^(long long e) {
    Matrix ret;
    Matrix tmp = *this;
    ret.data[0][0] = 1;
    ret.data[0][1] = 0;
    ret.data[1][0] = 0;
    ret.data[1][1] = 1;
    while (e) {
      if (e & 1) ret = ret * tmp;
      tmp = tmp * tmp;
      e >>= 1;
    }
    return ret;
  }
};
int f(long long n) {
  Matrix<long long> mat;
  mat.data[0][0] = 1;
  mat.data[0][1] = 1;
  mat.data[1][0] = 1;
  mat.data[1][1] = 0;
  if (n == 0) return 1;
  if (n == 1) return 2;
  mat = mat ^ (n - 1);
  return (mat.data[0][0] * 2 % m + mat.data[0][1] % m) % m;
}
int main() {
  long long n, k;
  int l;
  cin >> n >> k >> l >> m;
  if (l < 63 && (1LL << l) <= k) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 1;
  long long tp = 1, t = 2;
  int i;
  for (i = 0; (n >> i); i++) {
    if ((n >> i) & 1) tp = tp * t % m;
    t = t * t % m;
  }
  for (i = 0; i < l; i++) {
    if ((k >> i) & 1) {
      ans *= (tp - f(n) + m) % m;
      ans %= m;
    } else
      ans *= f(n), ans %= m;
  }
  cout << ans << endl;
  return 0;
}
