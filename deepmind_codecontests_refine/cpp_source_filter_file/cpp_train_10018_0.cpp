#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long xx = 0, flagg = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    flagg = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    xx = xx * 10 + ch - '0';
    ch = getchar();
  }
  return xx * flagg;
}
void pus(long long xx, long long flagg) {
  if (xx < 0) {
    putchar('-');
    xx = -xx;
  }
  if (xx >= 10) pus(xx / 10, 0);
  putchar(xx % 10 + '0');
  if (flagg == 1) putchar(' ');
  if (flagg == 2) putchar('\n');
  return;
}
long long n, m, i, j, k, x, l[2050], s[2050], c[2050], f[2050][2050];
int main() {
  n = read();
  m = read();
  for (i = n; i >= 1; i--) l[i] = read();
  for (i = n; i >= 1; i--) s[i] = read();
  for (i = 1; i <= n + m; i++) c[i] = read();
  m += 13;
  for (i = 0; i <= m; i++)
    for (j = 1; j <= n; j++) f[i][j] = -1000000000;
  for (i = 1; i <= n; i++) {
    for (j = n; j >= 1; j--)
      f[l[i]][j] = max(f[l[i]][j], f[l[i]][j - 1] + c[l[i]] - s[i]);
    x = n;
    for (j = l[i]; j <= m; j++, x >>= 1)
      for (k = 0; k <= x; k++)
        f[j + 1][k >> 1] = max(f[j + 1][k >> 1], f[j][k] + (k >> 1) * c[j + 1]);
  }
  pus(f[m][0], 2);
  return 0;
}
