#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using std::bitset;
using namespace std;
struct matrix {
  long long m[55][55];
} A, B, c, sum;
long long n, m, k;
matrix matrixtime(matrix a, matrix b, long long p) {
  long long i, j, k, tem;
  memset(c.m, 0, sizeof(c.m));
  ;
  for (i = 0; i < 55; i++)
    for (j = 0; j < 55; j++) {
      for (k = 0; k < 55; k++) c.m[i][j] += a.m[i][k] * b.m[k][j] % p;
      c.m[i][j] %= p;
    }
  return c;
}
matrix matrixpow(matrix A, long long n, long long p) {
  long long i, j, k, tem;
  memset(sum.m, 0, sizeof(sum.m));
  ;
  for (i = 0; i < 55; i++) sum.m[i][i] = 1;
  for (; n; n >>= 1) {
    if (n & 1) sum = matrixtime(sum, A, p);
    A = matrixtime(A, A, p);
  }
  return sum;
}
long long cau(char ch) {
  if (ch <= 'Z')
    return 26 + ch - 'A';
  else
    return ch - 'a';
}
int main() {
  long long i, j, tem;
  char st[4];
  while (scanf("%I64d%I64d%I64d", &n, &m, &k) != EOF) {
    memset(A.m, 0, sizeof(A.m));
    ;
    for (i = 0; i < m; i++)
      for (j = 0; j < m; j++) A.m[i][j] = 1;
    for (i = 1; i <= k; i++) {
      scanf("%2s", st);
      int a, b;
      a = cau(st[0]);
      b = cau(st[1]);
      A.m[a][b] = 0;
    }
    B = matrixpow(A, n - 1, 1000000007);
    long long ans = 0;
    for (i = 0; i < m; i++)
      for (j = 0; j < m; j++) ans = (ans + B.m[i][j]) % 1000000007;
    printf("%I64d\n", ans);
  }
  return 0;
}
