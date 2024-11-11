#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  int ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void rt(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10)
    rt(x / 10), putchar(x % 10 + '0');
  else
    putchar(x + '0');
}
const int maxn = 55, p = 1000000007, inv2 = 500000004;
int n;
long long f[maxn][maxn][maxn], g[maxn][maxn];
void upd(long long &x, long long y) { x = (x + y) % p; }
void prepare() {
  f[0][0][0] = 1;
  for (int k = int(0); k <= (int)(n - 1); k++)
    for (int j = int(0); j <= (int)(n); j++)
      for (int i = int(0); i <= (int)(n - j); i++) {
        long long &v = f[i][j][k];
        if (j) {
          if (i > 1) upd(v, f[i - 2][j - 1][k] * (i * (i - 1) / 2));
          if (i && j > 1) upd(v, f[i][j - 2][k] * i * (j - 1));
          if (j > 2) upd(v, f[i + 2][j - 3][k] * ((j - 1) * (j - 2) / 2));
          if (i) upd(v, f[i - 1][j - 1][k - 1] * i);
          if (j > 1) upd(v, f[i + 1][j - 2][k - 1] * (j - 1));
          upd(v, f[i][j - 1][k - 2] * inv2);
        } else if (i) {
          if (i > 1) upd(v, f[i - 2][j][k] * (i - 1));
          upd(v, f[i - 1][j][k - 1]);
        }
      }
  long long fac = 1;
  for (int k = int(0); k <= (int)(n - 1); k++) {
    for (int i = int(0); i <= (int)(n); i++)
      for (int j = int(0); j <= (int)(n - i); j++) (f[i][j][k] *= fac) %= p;
    (fac *= k + 1) %= p;
  }
}
int a[maxn];
int main() {
  n = rd();
  for (int i = int(1); i <= (int)(n); i++) a[i] = rd();
  prepare();
  g[1][a[1]] = 1;
  long long v;
  for (int i = int(1); i <= (int)(n - 1); i++)
    for (int j = int(1); j <= (int)(n - i); j++)
      if ((v = g[i][j])) {
        int n1 = 0, n2 = 0;
        for (int k = int(i + 1); k <= (int)(i + j); k++)
          if (a[k] == 2)
            n1++;
          else
            n2++;
        for (int k = int(0); k <= (int)(n1 + 2 * n2); k++)
          upd(g[i + j][k], v * f[n1][n2][k]);
      }
  rt(g[n][0]), putchar('\n');
}
