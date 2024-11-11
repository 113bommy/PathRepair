#include <bits/stdc++.h>
using namespace std;
long long n, x, y, p, sum, a[1001001], T[4][4], A[4][4], F[4][4];
inline void init() {
  T[0][0] = 3, T[0][1] = -1, T[0][2] = 0, T[0][3] = 0;
  T[1][0] = 0, T[1][1] = 1, T[1][2] = 0, T[1][3] = 0;
  T[2][0] = 0, T[2][1] = 0, T[2][2] = 1, T[2][3] = 1;
  T[3][0] = 0, T[3][1] = 0, T[3][2] = 1, T[3][3] = 0;
  A[0][0] = 1, A[0][1] = 0, A[0][2] = 0, A[0][3] = 0;
  A[1][0] = 0, A[1][1] = 1, A[1][2] = 0, A[1][3] = 0;
  A[2][0] = 0, A[2][1] = 0, A[2][2] = 1, A[2][3] = 0;
  A[3][0] = 0, A[3][1] = 0, A[3][2] = 0, A[3][3] = 1;
}
inline void mult(long long L[4][4], long long R[4][4], long long D[4][4]) {
  int i, j, k;
  long long M[4][4] = {};
  for (i = 0; i < 4; ++i)
    for (j = 0; j < 4; ++j)
      for (k = 0; k < 4; ++k)
        M[i][j] = ((M[i][j] + L[i][k] % p * R[k][j] % p) % p + p) % p;
  for (i = 0; i < 4; ++i)
    for (j = 0; j < 4; ++j) D[i][j] = M[i][j];
}
inline void power(long long exp) {
  while (exp > 0) {
    if (exp & 1) mult(A, T, A);
    exp >>= 1;
    mult(T, T, T);
  }
}
long long solve() {
  init();
  F[0][0] = sum % p;
  F[1][0] = (a[n - 1] + a[0]) % p;
  F[2][0] = a[n - 1] % p;
  F[3][0] = a[n - 2] % p;
  power(x);
  mult(A, F, F);
  init();
  F[1][0] = (F[2][0] + a[0]) % p;
  power(y);
  mult(A, F, F);
  return F[0][0];
}
int main() {
  scanf("%lld %lld %lld %lld", &n, &x, &y, &p);
  for (int i = 0; i < n; ++i) scanf("%lld", a + i), sum += a[i];
  cout << (n == 1 ? a[0] % p : solve()) << endl;
  return 0;
}
