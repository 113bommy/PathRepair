#include <bits/stdc++.h>
using namespace std;
int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}
int d, p, C[20][20], M[20][20];
int qpow(int a, int b) {
  int c = 1;
  for (; b; b >>= 1, a = 1ll * a * a % p)
    if (b & 1) c = 1ll * c * a % p;
  return c;
}
void Gauss(int n) {
  for (int i = 0; i <= n; ++i) {
    if (!M[i][i]) {
      for (int j = i + 1; j <= n; ++j)
        if (M[j][i]) {
          swap(M[i], M[j]);
          break;
        }
    }
    int inv = qpow(M[i][i], p - 2);
    for (int j = i + 1; j <= n; ++j) {
      int t = 1ll * M[j][i] * inv % p;
      for (int k = 0; k <= n + 1; ++k)
        M[j][k] = (M[j][k] - 1ll * t * M[i][k] % p + p) % p;
    }
  }
  for (int i = n; ~i; --i) {
    M[i][n + 1] = 1ll * M[i][n + 1] * qpow(M[i][i], p - 2) % p;
    for (int j = 0; j < i; ++j)
      M[j][n + 1] = (M[j][n + 1] - 1ll * M[i][n + 1] * M[j][i] % p + p) % p;
  }
}
int qmul(int a, int b) {
  int c = 0;
  for (; b; b >>= 1, a = (a + a) % p)
    if (b & 1) c = (c + a) % p;
  return c;
}
void mul(int a, int b, int c) {
  printf("+ 5000 5000 %d\n", c);
  printf("+ %d 5000 4999\n", a);
  for (; b; b >>= 1) {
    if (b & 1) printf("+ %d 4999 %d\n", c, c);
    puts("+ 4999 4999 4999");
  }
}
void sub(int a, int b, int c) {
  mul(4996, p - 1, 4997);
  mul(4997, b, 4998);
  printf("+ %d 4998 %d\n", a, c);
}
void sub2(int a, int b, int c) {
  mul(b, p - 1, 4998);
  printf("+ %d 4998 %d\n", a, c);
}
void pow2(int a, int b) {
  printf("+ 5000 5000 %d\n", b);
  printf("+ 5000 %d 4995\n", a);
  for (int i = 0; i <= d; ++i) {
    printf("^ 4995 4994");
    mul(4994, M[i][d + 1], 4993);
    printf("+ %d 4993 %d\n", b, b);
    puts("+ 4992 4995 4995");
  }
}
void solve() {
  puts("+ 1 2 3");
  pow2(3, 4);
  pow2(1, 5);
  pow2(2, 6);
  puts("+ 5 6 7");
  sub2(4, 7, 8);
  mul(8, qpow(2, p - 2), 9);
  puts("f 9");
}
int main() {
  d = read(), p = read();
  for (int i = p - 1; i; i >>= 1) {
    if (i & 1) puts("+ 4999 5000 5000");
    puts("+ 4999 4999 4999");
  }
  for (int i = C[0][0] = 1; i <= d; ++i)
    for (int j = C[i][0] = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
  for (int i = 0; i <= d; ++i)
    for (int j = 0; j <= d; ++j)
      M[i][j] = 1ll * C[d][d - i] * qpow(j, d - i) % p;
  M[2][d + 1] = 1;
  Gauss(d);
  solve();
  return 0;
}
