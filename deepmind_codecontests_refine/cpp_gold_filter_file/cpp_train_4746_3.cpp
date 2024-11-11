#include <bits/stdc++.h>
using namespace std;
const int maxn = 255;
const int md = 1e9 + 7;
char s[maxn * 4][maxn * 4];
int a[maxn][maxn], f[maxn], h[maxn], g[maxn], z[maxn];
int n, m;
bool q(int x, int y) { return s[x][y] == 'O'; }
int solve(int x, int y) {
  if (q(x, y) && q(x, y + 1) && q(x, y + 2) && q(x + 2, y) && q(x + 2, y + 1) &&
      q(x + 2, y + 2))
    return 1;
  if (q(x, y) && q(x + 1, y) && q(x + 2, y) && q(x, y + 2) && q(x + 1, y + 2) &&
      q(x + 2, y + 2))
    return 2;
  if (q(x, y) && q(x + 2, y) && q(x + 2, y + 2) && q(x, y + 2)) return 3;
  if (q(x, y) && q(x + 2, y + 2)) return 1;
  if (q(x + 2, y) && q(x, y + 2)) return 2;
  return 3;
}
bool ver(int x, int y) { return (a[x][y] & 2) > 0; }
bool hor(int x, int y) { return (a[x][y] & 1) > 0; }
int main() {
  scanf("%d%d", &m, &n);
  if ((m * n) % 2) {
    printf("0");
    return 0;
  }
  for (int i = 0; i <= 4 * m; ++i) scanf("%s", s[i]);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = solve(4 * i + 1, 4 * j + 1);
    }
  }
  if (m % 2 == 0)
    for (int j = 0; j < n; ++j) {
      h[j] = 1;
      for (int i = 0; i < m; ++i) h[j] &= ver(i, j);
    }
  for (int j = 1; j < n; ++j) {
    memset(z, 0, sizeof(z));
    z[0] = 1;
    for (int i = 0; i < m; ++i) {
      if (hor(i, j) && hor(i, j - 1)) z[i + 1] += z[i];
      if (i && ver(i, j) && ver(i, j - 1) && ver(i - 1, j) && ver(i - 1, j - 1))
        z[i + 1] += z[i - 1];
      z[i + 1] %= md;
    }
    g[j] = (z[m] + md - ((h[j] & h[j - 1]) > 0)) % md;
  }
  f[0] = 1;
  for (int j = 0; j < n; ++j) {
    f[j + 1] = f[j] * h[j];
    if (j) f[j + 1] = (1ll * f[j - 1] * g[j] + f[j + 1]) % md;
  }
  printf("%d", f[n]);
  return 0;
}
