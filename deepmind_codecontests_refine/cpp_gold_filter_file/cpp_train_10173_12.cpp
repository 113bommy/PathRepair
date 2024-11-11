#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  int s = 0;
  while (ch = getchar(), ch < '0' || ch > '9')
    ;
  s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int N = 1010;
double f[N][N];
int n, m;
int main() {
  n = get();
  m = get();
  int v = max(n, m);
  for (int i = 0; i <= v; i++) f[0][i] = 1.0 / (i + 1);
  for (int i = 0; i <= v; i++) f[i][0] = 1;
  for (int s = 2; s <= v + v; s++)
    for (int j = 1; j <= min(v, s - 1); j++) {
      int i = s - j;
      if (i > v) continue;
      double k0 = double(j) / (j + 1) * (1 - f[j - 1][i]),
             k1 = 1.0 / (j + 1) + double(j) / (j + 1) * (1 - f[j - 1][i]),
             b0 = 1, b1 = 1.0 - f[j][i - 1];
      k0 -= b0;
      k1 -= b1;
      double p = (b1 - b0) / (k0 - k1);
      f[i][j] = k0 * p + b0;
    }
  printf("%.16lf %.16lf\n", f[n][m], 1.0 - f[n][m]);
  return 0;
}
