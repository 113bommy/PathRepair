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
const int mo = 1e9 + 7, N = 507;
inline int fk(int x) { return x >= mo ? x - mo : x; }
int n, m;
int C[N][N], f[N][N];
int mi[N], mi_1[N];
int main() {
  n = read(), m = read();
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = fk(C[i - 1][j] + C[i - 1][j - 1]);
  }
  mi[0] = mi_1[0] = 1;
  for (int i = 1; i <= n; i++) {
    mi[i] = 1ll * mi[i - 1] * m % mo;
    mi_1[i] = 1ll * mi_1[i - 1] * (m - 1) % mo;
  }
  for (int j = 1; j <= n; j++) f[1][j] = 1ll * C[n][j] * mi_1[n - j] % mo;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      for (int k = i - 1; k <= j; k++) {
        int x = 1ll * f[i - 1][k] * C[n - k][j - k] % mo;
        int y = 1ll * mi_1[n - j] * mi[k] % mo;
        f[i][j] = fk(f[i][j] + 1ll * x * y % mo);
        if (j == k)
          f[i][j] = fk(f[i][j] - 1ll * mi_1[n] * f[i - 1][k] % mo + mo);
      }
    }
  printf("%d\n", f[n][n]);
  return 0;
}
