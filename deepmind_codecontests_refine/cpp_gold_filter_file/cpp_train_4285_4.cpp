#include <bits/stdc++.h>
using namespace std;
const long long N = 1e2 + 5;
const long long p = 1e9 + 7;
long long read() {
  long long s = 0;
  char c = getchar(), lc = '+';
  while (c < '0' || '9' < c) lc = c, c = getchar();
  while ('0' <= c && c <= '9') s = s * 10 + c - '0', c = getchar();
  return lc == '-' ? -s : s;
}
void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10)
    putchar(x + '0');
  else {
    write(x / 10);
    putchar(x % 10 + '0');
  }
}
void print(long long x, char c = '\n') {
  write(x);
  putchar(c);
}
long long power(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % p;
    a = a * a % p;
    b /= 2;
  }
  return ret;
}
inline void Mod(long long &x) {
  if (x >= p) x -= p;
}
struct Matrix {
  long long a[N][N];
  Matrix() { memset(a, 0, sizeof(a)); }
} t;
struct Vector {
  long long a[N];
  Vector() { memset(a, 0, sizeof(a)); }
} ans;
Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix ret;
  for (register long long i = 0; i <= 100; i++)
    for (register long long k = 0; k <= 100; k++)
      for (register long long j = 0; j <= 100; j++)
        Mod(ret.a[i][j] += a.a[i][k] * b.a[k][j] % p);
  return ret;
}
Vector operator*(const Matrix &a, const Vector &b) {
  Vector ret;
  for (register long long i = 0; i <= 100; i++)
    for (register long long k = 0; k <= 100; k++)
      Mod(ret.a[k] += b.a[i] * a.a[i][k] % p);
  return ret;
}
long long a[N];
signed main() {
  long long n = read(), k = read(), x = 0, y = 0, sx = 0,
            inv = power(n * (n - 1) / 2, p - 2);
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) x += a[i] == 0;
  for (long long i = 1; i <= n; i++) y += a[i] == 1;
  for (long long i = 1; i <= x; i++) sx += a[i] == 1;
  ans.a[sx] = 1;
  for (long long i = 0; i <= x; i++) {
    if (i > 0) t.a[i][i - 1] = i * i * inv % p;
    if (i < x && i < y) t.a[i][i + 1] = (x - i) * (y - i) * inv % p;
    t.a[i][i] =
        (n * (n - 1) / 2 - i * i - (i < x && i < y) * (x - i) * (y - i)) * inv %
        p;
  }
  while (k) {
    if (k & 1) ans = t * ans;
    t = t * t;
    k /= 2;
  }
  print(ans.a[0]);
  return 0;
}
