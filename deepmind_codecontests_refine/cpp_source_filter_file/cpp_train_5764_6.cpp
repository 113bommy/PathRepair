#include <bits/stdc++.h>
using namespace std;
long long mod;
const int MAX = 2;
typedef struct {
  int m[MAX][MAX];
} Matrix;
Matrix P = {
    1,
    1,
    0,
    3,
};
Matrix I = {
    1,
    0,
    0,
    1,
};
Matrix matrixmul(Matrix a, Matrix b) {
  int i, j, k;
  Matrix c;
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++) {
      c.m[i][j] = 0;
      for (k = 0; k < MAX; k++) c.m[i][j] += (a.m[i][k] * b.m[k][j]) % mod;
      c.m[i][j] %= mod;
    }
  return c;
}
Matrix quickpow(long long n) {
  Matrix m = P, b = I;
  while (n >= 1) {
    if (n & 1) b = matrixmul(b, m);
    n = n >> 1;
    m = matrixmul(m, m);
  }
  return b;
}
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    mod = (long long)m;
    Matrix ans = quickpow((long long)(n - 1));
    cout << (2LL * ans.m[0][1] + 2LL * ans.m[1][1]) % mod << endl;
  }
  return 0;
}
