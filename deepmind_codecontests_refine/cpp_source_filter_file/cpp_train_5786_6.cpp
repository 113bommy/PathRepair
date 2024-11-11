#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = 1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + ch - 48;
  return f ? -x : x;
}
inline void write(long long x) {
  if (x < 10)
    putchar(x + 48);
  else
    write(x / 10), putchar(x % 10 + 48);
}
inline void writeln(long long x) {
  if (x < 0) putchar('-'), x = -x;
  write(x);
  putchar('\n');
}
int n, f[1 << 17][121], A[1 << 17], B[1 << 17];
struct data {
  int opt, a, b;
} c[17];
int main() {
  n = read();
  int suma = 0, sumb = 0;
  for (int i = 1; i <= n; i++) {
    char s[5];
    scanf("%s", s);
    if (s[0] == 'R')
      c[i].opt = 0;
    else
      c[i].opt = 1;
    c[i].a = read();
    c[i].b = read();
    suma += c[i].a;
    sumb += c[i].b;
  }
  for (int i = 0; i < 1 << n; i++)
    for (int j = 1; j <= n; j++)
      if ((i >> (j - 1)) & 1) A[i] += c[i].opt ^ 1, B[i] += c[i].opt;
  memset(f, -1, sizeof f);
  f[0][0] = 0;
  for (int i = 0; i < 1 << n; i++)
    for (int j = 0; j <= 120; j++) {
      if (f[i][j] == -1) continue;
      for (int k = 1; k <= n; k++)
        if (!((i >> (k - 1)) & 1)) {
          int sa = min(c[k].a, A[i]);
          int sb = min(c[k].b, B[i]);
          f[i | (1 << (k - 1))][j + sa] =
              max(f[i | (1 << (k - 1))][j + sa], f[i][j] + sb);
        }
    }
  int ans = max(suma, sumb);
  for (int i = 0; i <= 120; i++)
    if (f[(1 << n) - 1][i] != -1)
      ans = min(ans, max(suma - i, sumb - f[(1 << n) - 1][i]));
  writeln(ans + n);
  return 0;
}
