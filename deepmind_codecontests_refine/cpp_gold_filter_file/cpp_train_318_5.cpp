#include <bits/stdc++.h>
using namespace std;
const int MAXN = 205;
const long long INF = 1e18;
template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x *= f;
}
template <typename T>
void write(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void writeln(T x) {
  write(x);
  puts("");
}
int n, t, x;
long long a[MAXN], b[MAXN], c[MAXN];
long long sa[MAXN], sb[MAXN], sc[MAXN];
long long f[MAXN][MAXN][2], g[MAXN][MAXN][2];
long long divx(long long a) {
  if (a <= 0)
    return 0;
  else
    return (a - 1) / x + 1;
}
int main() {
  read(n), read(t), read(x);
  for (int i = 1; i <= n; i++) {
    read(a[i]), sa[i] = sa[i - 1] + a[i];
    read(b[i]), sb[i] = sb[i - 1] + b[i];
    read(c[i]), sc[i] = sc[i - 1] + c[i];
  }
  n++, a[n] = c[n] = INF, b[n] = 0;
  sa[n] = sa[n - 1] + a[n];
  sb[n] = sb[n - 1] + b[n];
  sc[n] = sc[n - 1] + c[n];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= t; j++) {
      f[i][j][0] = g[i][j][0] = INF;
      if (b[i] * j <= c[i] && f[i - 1][j][0] != INF) {
        f[i][j][0] = f[i - 1][j][0];
        g[i][j][0] = divx(sb[i - 1] * j);
        if (g[i][j][0] * x > sb[i] * j) g[i][j][0] = INF;
      }
      for (int k = 0; k <= j - 1; k++) {
        if (g[i][k][0] != INF) {
          long long lft = sb[i] * k - g[i][k][0] * x;
          long long cnt = divx(b[i] * (j - k) + lft - c[i]);
          if ((g[i][k][0] + cnt) * x > sb[i] * k) continue;
          chkmin(f[i][j][0], g[i][k][0] + cnt + f[i - 1][j - k][0]);
          long long tmp = divx(sb[i - 1] * (j - k));
          if (f[i - 1][j - k][0] != INF &&
              (g[i][k][0] + cnt + tmp) * x <= sb[i] * j)
            chkmin(g[i][j][0], g[i][k][0] + cnt + tmp);
        }
      }
      f[i][j][1] = g[i][j][1] = INF;
      if (a[i] + b[i] * j <= c[i] && f[i - 1][j][1] != INF) {
        f[i][j][1] = f[i - 1][j][1];
        g[i][j][1] = divx(sa[i - 1] + sb[i - 1] * j);
        if (g[i][j][1] * x > sa[i] + sb[i] * j) g[i][j][1] = INF;
      }
      for (int k = 0; k <= j - 1; k++) {
        if (g[i][k][1] != INF) {
          long long lft = sa[i] + sb[i] * k - g[i][k][1] * x;
          long long cnt = divx(b[i] * (j - k) + lft - c[i]);
          if ((g[i][k][1] + cnt) * x > sa[i] + sb[i] * k) continue;
          chkmin(f[i][j][1], g[i][k][1] + cnt + f[i - 1][j - k][0]);
          long long tmp = divx(sb[i - 1] * (j - k));
          if (f[i - 1][j - k][0] != INF &&
              (g[i][k][1] + cnt + tmp) * x <= sa[i] + sb[i] * j)
            chkmin(g[i][j][1], g[i][k][1] + cnt + tmp);
        }
      }
    }
  writeln(f[n][t][1]);
  return 0;
}
