#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool f = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = 1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return f ? -x : x;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(long long x) {
  write(x);
  puts("");
}
void writep(long long x) {
  write(x);
  putchar(' ');
}
long long const N = 2e3 + 3;
long long const P = 233;
long long const Mo = 1e9 + 7;
long long n, m, ans, res, f[2][N][N], g[2][N][N];
long long base[N], Hash[N], Hash1[2][N], Hash2[2][N];
char a[2][N], b[N];
long long get1(long long l, long long r, long long i) {
  return Hash1[i][r] - Hash1[i][l - 1] * base[r - l + 1];
}
long long get2(long long l, long long r, long long i) {
  return Hash2[i][l] - Hash2[i][r + 1] * base[r - l + 1];
}
long long merge(long long x, long long y, long long len) {
  return x * base[len] + y;
}
void dp() {
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (long long i = 1; i <= m; i++) Hash[i] = Hash[i - 1] * P + b[i] - 'a' + 1;
  for (long long i = 0; i <= 1; i++)
    for (long long j = 1; j <= n; j++)
      for (long long k = j, len = 2 * (j - k + 1); k && len <= m; k--, len += 2)
        if (merge(get2(k, j, i ^ 1), get1(k, j, i), j - k + 1) == Hash[len]) {
          if (len == m)
            res++;
          else
            g[i][j][len] = 1;
        }
  for (long long i = 0; i <= 1; i++)
    for (long long j = 1; j <= n; j++)
      if (a[i][j] == b[1]) g[i][j][1] = 1;
  for (long long k = 1; k < m; k++)
    for (long long i = 0; i <= 1; i++)
      for (long long j = 1; j <= n; j++) {
        if (j < n && a[i][j + 1] == b[k + 1])
          f[i][j + 1][k + 1] = (f[i][j + 1][k + 1] + g[i][j][k]) % Mo;
        if (j < n && a[i][j + 1] == b[k + 1])
          f[i][j + 1][k + 1] = (f[i][j + 1][k + 1] + f[i][j][k]) % Mo;
        if (a[i ^ 1][j] == b[k + 1])
          g[i ^ 1][j][k + 1] = (g[i ^ 1][j][k + 1] + f[i][j][k]) % Mo;
      }
  for (long long i = m; i; i--) Hash[i] = Hash[i + 1] * P + b[i] - 'a' + 1;
  for (long long i = 0; i <= 1; i++)
    for (long long j = 1; j <= n; j++) {
      if (a[i][j] == b[m]) {
        if (m == 1)
          ans = (ans + 1) % Mo;
        else
          ans = (ans + f[i][j - 1][m - 1] + g[i][j - 1][m - 1]) % Mo;
      }
      for (long long k = j, len = 2 * (k - j + 1); k <= n && len <= m;
           k++, len += 2) {
        if (merge(get1(j, k, i ^ 1), get2(j, k, i), k - j + 1) ==
            Hash[m - len + 1]) {
          if (len == m && m != 2)
            res++;
          else
            ans = (ans + f[i][j - 1][m - len] + g[i][j - 1][m - len]) % Mo;
        }
      }
    }
}
signed main() {
  scanf("%s", a[0] + 1);
  scanf("%s", a[1] + 1);
  scanf("%s", b + 1);
  n = strlen(a[0] + 1);
  m = strlen(b + 1);
  base[0] = 1;
  for (long long i = 1; i <= max(n, m); i++) base[i] = base[i - 1] * P;
  for (long long i = 0; i <= 1; i++)
    for (long long j = 1; j <= n; j++)
      Hash1[i][j] = Hash1[i][j - 1] * P + a[i][j] - 'a' + 1;
  for (long long i = 0; i <= 1; i++)
    for (long long j = n; j; j--)
      Hash2[i][j] = Hash2[i][j + 1] * P + a[i][j] - 'a' + 1;
  dp();
  reverse(b + 1, b + m + 1);
  dp();
  ans = (ans + res / 2) % Mo;
  if (m == 1) ans >>= 1;
  writeln(ans);
  return 0;
}
