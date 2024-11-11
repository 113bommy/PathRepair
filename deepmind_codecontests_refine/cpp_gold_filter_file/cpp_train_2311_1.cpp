#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int n = 10, N = 107;
int id[N][N], to[N];
double f[N];
int main() {
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1)
      for (int j = 1; j <= n; j++) id[i][j] = ++tot;
    else
      for (int j = n; j >= 1; j--) id[i][j] = ++tot;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int a = read();
      if (a) to[id[i][j]] = id[i - a][j];
    }
  for (int i = 2; i <= 6; i++) {
    for (int j = 1; j < i; j++) f[i] += (f[i - j] + 1.0) / 6;
    f[i] += (7.0 - i) / 6;
    f[i] /= (1.0 - (7.0 - i) / 6);
  }
  for (int i = 7; i <= tot; i++) {
    for (int j = 1; j <= 6; j++) f[i] += (f[i - j] + 1.0) / 6;
    if (!to[i]) continue;
    double mi = 0;
    int t = to[i];
    if (t == 1) {
      f[i] = 0;
      continue;
    }
    for (int j = 1; j <= 6; j++)
      if (t - j > 0) mi += (f[t - j] + 1.0) / 6;
    if (t <= 6) mi += (7.0 - t) / 6, mi /= (1.0 - (7.0 - t) / 6);
    f[i] = min(f[i], mi);
  }
  printf("%.10f\n", f[tot]);
  return 0;
}
