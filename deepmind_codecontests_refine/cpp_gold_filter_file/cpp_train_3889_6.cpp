#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000000000;
int c[1001][1001];
int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  long long s = 0, sij = 0, si = 0, sj = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int p = (i - 1) * 4 + 2, q = (j - 1) * 4 + 2;
      scanf("%d", &c[i][j]);
      s += c[i][j];
      sij += (long long)c[i][j] * (p * p + q * q);
      si += c[i][j] * p;
      sj += c[i][j] * q;
    }
  }
  int x, y;
  long long ans = inf;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      int p = i * 4, q = j * 4;
      long long temp = s * (p * p + q * q) - 2 * si * p - 2 * sj * q + sij;
      if (temp < ans) {
        ans = temp;
        x = i;
        y = j;
      }
    }
  }
  printf("%I64d\n%d %d\n", ans, x, y);
  return 0;
}
