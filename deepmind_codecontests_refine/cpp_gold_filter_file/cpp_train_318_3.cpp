#include <bits/stdc++.h>
using namespace std;
char buf[25];
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 210;
long long f[maxn][maxn][2], g[maxn][maxn][2];
long long a[maxn], b[maxn], c[maxn], s1[maxn], s2[maxn];
long long n, t, k;
long long read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f ? -x : x;
}
void write(long long x) {
  if (!x) {
    putchar('0');
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  int cnt = 0;
  while (x) {
    buf[++cnt] = '0' + x % 10;
    x /= 10;
  }
  for (int i = cnt; i >= 1; --i) putchar(buf[i]);
}
long long Div(long long x, long long y) {
  return x % y == 0 ? x / y : x / y + 1;
}
int main() {
  n = read();
  t = read();
  k = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    b[i] = read();
    c[i] = read();
  }
  ++n;
  a[n] = b[n] = INT_MAX;
  c[n] = inf;
  for (int i = 1; i <= n; ++i) {
    s1[i] = s1[i - 1] + a[i];
    s2[i] = s2[i - 1] + b[i];
  }
  memset(f, 63, sizeof(f));
  memset(g, 63, sizeof(g));
  for (int i = 0; i <= t; ++i)
    f[0][i][0] = f[0][i][1] = g[0][i][0] = g[0][i][1] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= t; ++j)
      for (int l = 0; l <= 1; ++l) {
        if (l * a[i] + j * b[i] <= c[i] && f[i - 1][j][l] < inf) {
          f[i][j][l] = f[i - 1][j][l];
          long long L = l * s1[i - 1] + j * s2[i - 1];
          if (Div(L, k) * k <= l * s1[i] + j * s2[i]) g[i][j][l] = Div(L, k);
        }
        for (int r = 0; r <= j - 1; ++r)
          if (g[i][r][l] < inf) {
            long long rem = l * s1[i] + r * s2[i] - k * g[i][r][l],
                      need = Div(max(rem + (j - r) * b[i] - c[i], 0ll), k);
            if (rem < 0) continue;
            if (need * k <= rem && f[i - 1][j - r][0] < inf) {
              f[i][j][l] =
                  min(f[i][j][l], g[i][r][l] + need + f[i - 1][j - r][0]);
              long long L = (j - r) * s2[i - 1];
              if (Div(L, k) * k <= (j - r) * s2[i] + (rem - need * k))
                g[i][j][l] = min(g[i][j][l], g[i][r][l] + need + Div(L, k));
            }
          }
      }
  write(f[n][t][1]);
  putchar('\n');
  return 0;
}
