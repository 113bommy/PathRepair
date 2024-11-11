#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
struct Matrix {
  long long a[100][100];
  Matrix() { memset(a, 0, sizeof(a)); }
  Matrix operator*(Matrix b) const {
    Matrix c;
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        for (int k = 0; k < 100; k++) {
          c.a[i][j] += a[i][k] * b.a[k][j];
          if (c.a[i][j] >= MOD) c.a[i][j] -= MOD;
        }
      }
    }
    return c;
  }
  void id() {
    for (int i = 0; i < 100; i++) a[i][i] = 1;
  }
};
Matrix pow(Matrix x, long long e) {
  Matrix ret;
  ret.id();
  while (e) {
    if (e & 1) ret = ret * x;
    x = x * x;
    e >>= 1LL;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, x, p;
  long long b;
  cin >> n >> b >> k >> x;
  Matrix M;
  for (int i = 0; i < n; i++) {
    cin >> p;
    for (int j = 0; j < x; j++) {
      int newmod = 10 * j + p;
      newmod %= x;
      M.a[j][newmod]++;
    }
  }
  M = pow(M, b);
  cout << M.a[0][k];
  return 0;
}
