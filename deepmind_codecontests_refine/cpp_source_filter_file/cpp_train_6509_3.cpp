#include <bits/stdc++.h>
const int N = 200010;
const long double inf = 1e100;
int n, m, i, j, x;
long double b[N], c[N], s[N], f[2][N];
void dp(int l, int r, int dl, int dr) {
  int mid = (l + r) >> 1, dm;
  long double g = inf;
  for (int i = dl; i <= dr && i < mid; i++) {
    long double tmp = f[x ^ 1][i] + b[mid] - b[i] - s[i] * (c[mid] - c[i]);
    if (tmp < g) g = tmp, dm = i;
  }
  f[x][mid] = g;
  if (l < mid) dp(l, mid - 1, dl, dm);
  if (r > mid) dp(mid + 1, r, dm, dr);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    long double t = x;
    s[i] = s[i - 1] + t;
    b[i] = b[i - 1] + s[i] / t;
    c[i] = c[i - 1] + 1.0 / t;
  }
  for (i = 1; i <= n; i++) f[0][i] = inf;
  for (i = x = 1; i <= m; i++, x ^= 1) {
    for (j = 0; j <= n; j++) f[x][j] = inf;
    dp(1, n, 0, n);
    if (i == m) printf("%.10f", (double)f[x][n]);
  }
  return 0;
}
