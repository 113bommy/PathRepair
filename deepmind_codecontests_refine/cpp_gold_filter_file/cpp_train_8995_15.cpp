#include <bits/stdc++.h>
using namespace std;
long long n, x, y, dx, dy, t;
long long g[11], f[11], c[11][11], b[11][11], a[11][11];
void mul2() {
  memset(g, 0, sizeof g);
  for (int i = 0; i <= 5; ++i)
    for (int k = 0; k <= 5; ++k) (g[i] += c[i][k] * f[k]) %= n;
  memcpy(f, g, sizeof f);
}
void mul(long long c[][11], long long a[][11], long long b[][11]) {
  for (int i = 0; i <= 5; ++i)
    for (int j = 0; j <= 5; ++j) {
      c[i][j] = 0;
      for (int k = 0; k <= 5; ++k) (c[i][j] += a[i][k] * b[k][j]) %= n;
    }
}
int main() {
  cin >> n >> x >> y >> dx >> dy >> t;
  f[0] = x - 1;
  f[1] = y - 1;
  f[2] = dx;
  f[3] = dy;
  f[4] = 0;
  f[5] = 1;
  a[0][0] = 2;
  a[0][1] = a[0][2] = a[0][4] = 1;
  a[0][5] = 2;
  a[1][1] = 2;
  a[1][0] = a[1][3] = a[1][4] = 1;
  a[1][5] = 2;
  a[2][0] = a[2][1] = a[2][2] = a[2][4] = 1;
  a[2][5] = 2;
  a[3][0] = a[3][1] = a[3][3] = a[3][4] = 1;
  a[3][5] = 2;
  a[4][4] = a[4][5] = 1;
  a[5][5] = 1;
  for (int i = 0; i <= 5; ++i) c[i][i] = 1;
  for (int i = 0; i <= 62; ++i) {
    if ((t >> i) & 1) {
      mul(b, c, a);
      memcpy(c, b, sizeof c);
    }
    mul(b, a, a);
    memcpy(a, b, sizeof a);
  }
  mul2();
  if (f[0] < 0) f[0] += n;
  if (f[1] < 0) f[1] += n;
  printf("%I64d %I64d\n", f[0] + 1, f[1] + 1);
}
