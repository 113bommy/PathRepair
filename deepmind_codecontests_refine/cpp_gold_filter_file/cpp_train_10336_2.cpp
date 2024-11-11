#include <bits/stdc++.h>
inline void assign();
inline void close();
inline int getint();
inline void putint(int);
inline int min(int, int);
inline void prepare();
int n, m, p;
int c[1048576], l[1048576];
int f[5013][5013], g[5013];
int d[2][5013];
int main() {
  int sum = 1;
  n = getint(), m = getint(), p = getint();
  for (int i = 1; i <= n; i++) l[i] = getint();
  prepare();
  for (int i = 1; i <= n; i++) {
    memset(d[i & 1], 0, sizeof(d[i & 1]));
    for (int j = 1; j <= l[i]; j++)
      d[i & 1][j] = (1ll * sum * c[j] % p * f[l[i]][j] % p -
                     1ll * f[l[i]][j] * d[~i & 1][j] % p * g[j] % p + p) %
                    p;
    sum = 0;
    for (int j = 1; j <= l[i]; j++) sum = (sum + d[i & 1][j]) % p;
  }
  putint(sum);
  return 0;
}
inline void assign() {
  freopen("christmas.in", "r", stdin);
  freopen("christmas.out", "w", stdout);
}
inline void close() {
  fclose(stdin);
  fclose(stdout);
}
inline int getint() {
  register int num = 0;
  register char ch;
  do ch = getchar();
  while (ch < '0' || ch > '9');
  do num = num * 10 + ch - '0', ch = getchar();
  while (ch >= '0' && ch <= '9');
  return num;
}
inline void putint(int num) {
  char stack[16];
  register int top = 0;
  if (num == 0) stack[top = 1] = '0';
  for (; num; num /= 10) stack[++top] = num % 10 + '0';
  for (; top; top--) putchar(stack[top]);
  putchar('\n');
}
inline int min(int x, int y) { return x < y ? x : y; }
inline void prepare() {
  c[0] = 1;
  for (int i = 1; i <= m; i++) c[i] = 1ll * c[i - 1] * (m - i + 1) % p;
  f[0][0] = 1;
  for (int i = 1; i <= 5000; i++)
    for (int j = 1; j <= min(i, m); j++)
      f[i][j] = (1ll * f[i - 1][j] * (j - 1) % p + f[i - 1][j - 1]) % p;
  g[0] = 1;
  for (int i = 1; i <= 5000; i++) g[i] = 1ll * g[i - 1] * i % p;
}
