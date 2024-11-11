#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
struct node {
  int x, y;
} a[N];
int cmp(node a, node b) { return a.x < b.x; }
double f[55][55][55], ans;
int pd(double ans) {
  memset(f, 127, sizeof f);
  f[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].x == a[i - 1].x) {
      for (int j = 0; j <= i - 1; j++) {
        int nj = j ? j - 1 : j;
        for (int k = 0; k <= i - 1; k++) {
          if (f[i - 1][j][k] + a[i].x - ans * a[i].y < f[i][nj][k])
            f[i][nj][k] = f[i - 1][j][k] + a[i].x - ans * a[i].y;
          if (f[i - 1][j][k] < f[i][j][k + 1]) f[i][j][k + 1] = f[i - 1][j][k];
        }
      }
    } else {
      for (int j = 0; j <= i - 1; j++)
        for (int k = 0; k <= i - 1; k++)
          f[i - 1][j + k][0] =
              ((f[i - 1][j + k][0]) < (f[i - 1][j][k]) ? (f[i - 1][j + k][0])
                                                       : (f[i - 1][j][k]));
      for (int j = 0; j <= i - 1; j++) {
        int nj = j ? j - 1 : j;
        if (f[i - 1][j][0] + a[i].x - ans * a[i].y < f[i][nj][0])
          f[i][nj][0] = f[i - 1][j][0] + a[i].x - ans * a[i].y;
        if (f[i - 1][j][0] < f[i][j][1]) f[i][j][1] = f[i - 1][j][0];
      }
    }
  }
  return f[n][0][0] < 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].x);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].y);
  sort(a + 1, a + n + 1, cmp);
  for (double l = 0, r = 1e8; r - l > 1e-5;) {
    double m = (l + r) / 2;
    if (pd(m))
      ans = m, r = m;
    else
      l = m;
  }
  long long as = ceil((ans - 1e-5) * 1000);
  printf("%I64d\n", as);
}
