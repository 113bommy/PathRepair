#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005];
double ans;
double f[1005][1005];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    (x *= 10) += ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) f[i][j] = a[i] > a[j];
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    for (int j = 1; j <= n; j++) {
      f[j][x] = f[j][y] = 0.5 * (f[j][x] + f[j][y]);
      f[x][j] = f[y][j] = 1 - f[j][x];
    }
    f[x][y] = f[y][x] = 0.5;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) ans += f[i][j];
  printf("%.8lf", ans);
  return 0;
}
