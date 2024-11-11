#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || '9' < ch) f |= ch == '-', ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
int n, m, k[100009], g[1 << 20];
long long f[21][1 << 20];
char s[100009];
inline void fwt(long long *f) {
  long long x, y;
  for (int i = 0; i <= n - 1; i++)
    for (int S = 0; S <= (1 << n) - 1; S++)
      if (S & (1 << i))
        x = f[S - (1 << i)], y = f[S], f[S - (1 << i)] = x + y, f[S] = x - y;
}
int main() {
  n = read(), m = read();
  for (int i = 0; i <= n - 1; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++) k[j] += (s[j] - '0') << i;
  }
  for (int j = 1; j <= m; j++) f[0][k[j]] = 1;
  for (int S = 1; S <= (1 << n) - 1; S++)
    g[S] = g[S - (S & -S)] + 1, f[g[S]][S] = 1;
  for (int i = 0; i <= n; i++) fwt(f[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= (1 << n) - 1; j++) f[i][j] *= f[0][j];
  for (int i = 0; i <= n; i++) fwt(f[i]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= (1 << n) - 1; j++) f[i][j] /= (1 << n);
  int A = 0x3fffffff;
  for (int S = 0; S <= (1 << n) - 1; S++) {
    int a = 0;
    for (int i = 0; i <= n; i++) a += min(i, n - i) * f[i][S];
    A = min(A, a);
  }
  printf("%d\n", A);
  return 0;
}
