#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const double eps = 1e-10;
int n, vis[200];
double ans, f[200], p[200], now = 1.0, g;
inline double calc(int x) { return f[x] + (double)(1.0 - f[x]) * p[x]; }
int main() {
  n = read();
  for (register int i = 1; i <= n; i++) {
    int x = read();
    f[i] = p[i] = (double)x / 100.0, now *= f[i];
  }
  ans = n * now;
  for (register int i = n + 1; i <= 100000; i++) {
    int x = 1;
    for (register int j = 1; j <= n; j++) {
      if (calc(j) / f[j] > calc(x) / f[x]) x = j;
    }
    g = now * calc(x) / f[x], f[x] = calc(x), ans += i * (g - now), now = g;
  }
  printf("%.10lf\n", ans);
  return 0;
}
