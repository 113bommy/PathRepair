#include <bits/stdc++.h>
using namespace std;
long long mod;
class matrix {
 public:
  long long mat[2][2];
  matrix() {}
  void ini() {
    mat[0][0] = mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;
  }
  matrix(int v) {
    memset(mat, 0, sizeof mat);
    for (int i = 0; i < 2; ++i) mat[i][i] = v;
  }
};
matrix operator*(const matrix &a, const matrix &b) {
  matrix res(0);
  for (int k = 0; k < 2; ++k)
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        res.mat[i][j] += a.mat[i][k] * b.mat[k][j], res.mat[i][j] %= mod;
  return res;
}
matrix modex(matrix a, long long b) {
  matrix res(1);
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long f(long long v, long long le, long long ri) {
  return ri / v - (le - 1) / v;
}
int main() {
  long long x, y, k;
  cin >> mod >> x >> y >> k;
  long long p = 1;
  for (int i = 1; i <= 1000000; i++) {
    long long j = y / i;
    if (i > p && y / i - (x - 1) / i >= k) p = i;
    if (j > p && y / j - (x - 1) / j >= k) p = j;
  }
  if (p <= 2)
    cout << 1 % mod << endl;
  else {
    matrix res;
    res.ini();
    res = modex(res, p - 2);
    long long answer = (res.mat[0][0] + res.mat[0][1]) % mod;
    cout << answer << endl;
  }
  return 0;
}
