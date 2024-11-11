#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
int num[maxn];
typedef long long Matrix[maxn][maxn];
int sz;
const long long mod = 1e9 + 7;
void matrix_mul(Matrix A, Matrix B, Matrix res) {
  Matrix C;
  memset(C, 0, sizeof(C));
  for (int i = 0; i < sz; ++i)
    for (int j = 0; j < sz; ++j)
      for (int k = 0; k < sz; ++k)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
  memcpy(res, C, sizeof(C));
}
void matrix_pow(Matrix A, long long n, Matrix res) {
  Matrix a, r;
  memcpy(a, A, sizeof(a));
  memset(r, 0, sizeof(r));
  for (int i = 0; i < sz; ++i) r[i][i] = 1;
  while (n) {
    if (n & 1) matrix_mul(r, a, r);
    n >>= 1;
    matrix_mul(a, a, a);
  }
  memcpy(res, r, sizeof(r));
}
long long cal(long long num) {
  int res = 0;
  while (num) {
    if (num % 2 == 1) res++;
    num /= 2;
  }
  return res;
}
int main() {
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  sz = n;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &num[i]);
  }
  Matrix p;
  memset(p, 0, sizeof(p));
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      if (cal(num[r] ^ num[c]) % 3 == 0) p[r][c] = 1;
    }
  }
  Matrix A;
  memset(A, 0, sizeof(A));
  for (int i = 0; i < n; ++i) A[i][0] = 1;
  matrix_pow(p, k - 1, p);
  matrix_mul(p, A, A);
  long long res = 0;
  for (int i = 0; i < sz; ++i) res = (res + A[i][0]) % mod;
  printf("%lld\n", res);
  return 0;
}
