#include <bits/stdc++.h>
using namespace std;
bool b[2][2010];
long double f[2010][2010];
int numx, numy, n, m;
inline int Read() {
  char c = getchar();
  int num = 0;
  while ('0' > c || c > '9') c = getchar();
  while ('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
  return (num);
}
int main() {
  n = Read(), m = Read();
  for (int i = 1; i <= m; i++) {
    int x = Read(), y = Read();
    if (!b[0][x]) b[0][x] = 1, numx++;
    if (!b[1][y]) b[1][y] = 1, numy++;
  }
  for (int i = n; i >= numx; i--)
    for (int j = n; j >= numy; j--) {
      if (i == n && j == n) continue;
      long double num = 0.;
      num += (long double)(n - i) * (long double)j / (long double)(n * n) *
             (f[i + 1][j] + 1.);
      num += (long double)(n - j) * (long double)i / (long double)(n * n) *
             (f[i][j + 1] + 1.);
      num += (long double)(n - i) * (long double)(n - j) /
             (long double)(n * n) * (f[i + 1][j + 1] + 1.);
      num += (long double)(i * j) / (long double)(n * n);
      long double k = (long double)(n * n - i * j) / (long double)(n * n);
      f[i][j] = num / k;
    }
  printf("%.9lf\n", (double)f[numx][numy]);
}
