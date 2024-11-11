#include <bits/stdc++.h>
using namespace std;
int d, mod, A[12][12];
void qmo(int &x) { x += x >> 31 & mod; }
int ksm(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = (long long)a * a % mod)
    if (b & 1) r = (long long)r * a % mod;
  return r;
}
void Gauss(int n) {
  for (int i = 0; i < n; ++i) {
    if (!A[i][i])
      for (int j = i + 1; j < n; ++j)
        if (A[j][i]) {
          swap(A[i], A[j]);
          break;
        }
    int tmp = ksm(A[i][i], mod - 2);
    for (int j = i; j <= n; ++j) A[i][j] = (long long)A[i][j] * tmp % mod;
    for (int j = 0; j < n; ++j)
      if (j != i)
        for (int k = i + 1; k <= n; ++k)
          qmo(A[j][k] -= (long long)A[j][i] * A[i][k] % mod);
  }
}
void mul(int a, int b, int c) {
  printf("+ 1001 1001 %d\n", c);
  printf("+ %d 1001 1002\n", a);
  for (; b; b >>= 1) {
    if (b & 1) printf("+ %d 1002 %d\n", c, c);
    puts("+ 1002 1002 1002");
  }
}
void sub(int a, int b, int c) {
  mul(b, mod - 1, 1003);
  printf("+ %d 1003 %d\n", a, c);
}
void pw2(int a, int b) {
  printf("+ 1001 1001 %d\n", b);
  printf("+ %d 1001 1004\n", a);
  for (int i = 0; i <= d; ++i) {
    puts("^ 1004 1005");
    mul(1005, A[i][d + 1], 1006);
    printf("+ %d 1006 %d\n", b, b);
    if (i < d) puts("+ 1004 1007 1004");
  }
}
int main() {
  scanf("%d%d", &d, &mod);
  for (int i = 0; i <= d; ++i)
    for (int j = 0; j <= d; ++j) A[i][j] = ksm(j, d - i);
  A[2][d + 1] = ksm(d * (d - 1ll) >> 1, mod - 2);
  Gauss(d + 1);
  for (int i = mod - 1; i; i >>= 1) {
    if (i & 1) puts("+ 1000 1001 1001");
    puts("+ 1000 1000 1000");
  }
  puts("+ 1 2 3");
  pw2(1, 4);
  pw2(2, 5);
  pw2(3, 6);
  puts("+ 5 6 7");
  sub(4, 7, 8);
  mul(8, mod + 1 >> 1, 9);
  puts("f 9");
}
