#include <bits/stdc++.h>
using namespace std;
double f[500005][60 + 5];
int father[500005], n, q;
int main() {
  scanf("%d", &q);
  f[1][0] = 1;
  n = 1;
  while (q--) {
    int T, x;
    scanf("%d%d", &T, &x);
    if (T == 1) {
      n++;
      father[n] = x;
      f[n][0] = 1;
      double tmp1 = 0, tmp2 = 1;
      int tx = x;
      for (int i = 1; i <= 60; i++) {
        if (tx == 0) break;
        double tmp = f[tx][i];
        f[tx][i] = 1 - (1 - f[tx][i]) / (0.5 + 0.5 * (1 - tmp1)) *
                           (0.5 + 0.5 * (1 - tmp2));
        tmp1 = tmp;
        tmp2 = f[tx][i];
        tx = father[tx];
      }
    } else {
      double ans = 0;
      for (int i = 0; i <= 60; i++) ans = ans + i * (f[x][i] - f[x][i + 1]);
      printf("%.10lf\n", ans);
    }
  }
  return 0;
}
