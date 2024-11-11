#include <bits/stdc++.h>
using namespace std;
const int N = 2025, inf = 0x3f3f3f3f;
int read() {
  int f = 1, g = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) g = g * 10 + ch - '0';
  return f * g;
}
int n, m, a[N][N], f[N][N], g[N][N], b[N];
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) b[j] = a[i][j];
    sort(b + 1, b + m + 1);
    int cnt = unique(b + 1, b + m + 1) - b - 1;
    for (int j = 1; j <= m; j++) {
      int t = lower_bound(b + 1, b + cnt + 1, a[i][j]) - b;
      f[i][j] = t - 1;
      g[i][j] = n - t;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) b[j] = a[j][i];
    sort(b + 1, b + n + 1);
    int cnt = unique(b + 1, b + n + 1) - b - 1;
    for (int j = 1; j <= n; j++) {
      int t = lower_bound(b + 1, b + cnt + 1, a[j][i]) - b;
      f[j][i] = max(f[j][i], t - 1);
      g[j][i] = max(g[j][i], n - t);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d ", f[i][j] + g[i][j] + 1);
    printf("\n");
  }
  return 0;
}
