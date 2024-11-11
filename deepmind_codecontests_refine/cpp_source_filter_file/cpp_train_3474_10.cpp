#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:300000000")
const long double eps = 1e-20;
const long double pi = acos(-1.0);
const long long inf = 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const long long base = 1000 * 1000 * 1000 + 7;
using namespace std;
long long a[3111][3111], s[3111][3111];
int n, m, k;
long long fs(int xl, int yl, int xr, int yr) {
  return s[xr][yr] - s[xl - 1][yr] - s[xr][yl - 1] + s[xl - 1][yl - 1];
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) {
      int x;
      scanf("%d", &x);
      a[i + j][i - j + m] = x;
    }
  for (int i = (1); i <= (n + m); i++)
    for (int j = (1); j <= (m + n); j++)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
  long long ans = -1;
  int px, py;
  for (int i = (k); i <= (n - k + 1); i++)
    for (int j = (k); j <= (m - k + 1); j++) {
      int x = i + j, y = i - j + m;
      long long tmp = 0;
      for (int u = 0; u < (k); u++) tmp += fs(x - u, x + u, y - u, y + u);
      if (tmp > ans) {
        ans = tmp;
        px = i;
        py = j;
      }
    }
  printf("%d %d", px, py);
  return 0;
}
