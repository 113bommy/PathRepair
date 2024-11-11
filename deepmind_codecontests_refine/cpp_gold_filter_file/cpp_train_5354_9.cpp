#include <bits/stdc++.h>
using namespace std;
const int N = 2048;
int n, m;
bool a[N], b[N];
double f[N][N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x] = b[y] = 1;
  }
  int h = 0, c = 0;
  for (int i = 1; i <= n; ++i) h += a[i], c += b[i];
  f[n][n] = 0;
  for (int i = n; i >= 0; --i)
    for (int j = (i == n ? n - 1 : n); j >= 0; --j) {
      f[i][j] = 1;
      f[i][j] += 1.0 * (n - i) / n * j / n * f[i + 1][j];
      f[i][j] += 1.0 * i / n * (n - j) / n * f[i][j + 1];
      f[i][j] += 1.0 * (n - i) / n * (n - j) / n * f[i + 1][j + 1];
      f[i][j] /= 1.0 - 1.0 * i / n * j / n;
    }
  printf("%.10f\n", f[h][c]);
  return 0;
}
