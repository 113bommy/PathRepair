#include <bits/stdc++.h>
using namespace std;
double f[110][110], g[110][110];
int n, k;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
inline int c2(int n) { return (n * (n + 1)) >> 1; }
int a[110];
int main() {
  n = read();
  k = read();
  for (int i = (0); i <= (n - 1); i++) a[i] = read();
  int n2 = c2(n);
  for (k = min(k, 900); k--;) {
    for (int i = (0); i <= (n - 1); i++)
      for (int j = (i + 1); j <= (n - 1); j++) {
        g[i][j] = (c2(i) + c2(n - 1 - j) + c2(j - i - 1)) * f[i][j];
        for (int x = (i); x <= (i + j - 1); x++) {
          int a = max(0, x - j + 1), b = min(i, x - i);
          g[i][j] += (b - a + 1) * f[x - i][j];
        }
        for (int x = (i + j + 1); x <= (n + j - 1); x++) {
          int a = max(i + 1, x - n + 1), b = min(j, x - j);
          g[i][j] += (b - a + 1) * f[i][x - j];
        }
        for (int x = (j); x <= (n + i - 1); x++) {
          int a = max(0, x - n + 1), b = min(i, x - j);
          g[i][j] += (b - a + 1) * (1 - f[x - j][x - i]);
        }
        g[i][j] /= n2;
      }
    swap(f, g);
  }
  double ans = 0;
  for (int i = (0); i <= (n - 1); i++)
    for (int j = (i + 1); j <= (n - 1); j++) {
      ans += a[i] > a[j] ? 1 - f[i][j] : f[i][j];
    }
  printf("%.16lf\n", ans);
}
