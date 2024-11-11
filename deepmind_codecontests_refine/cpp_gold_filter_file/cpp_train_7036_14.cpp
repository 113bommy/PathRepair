#include <bits/stdc++.h>
using namespace std;
int T, n = 250, mx, si, a[252];
double X, V;
int main() {
  scanf("%d", &T);
  int i;
  while (T--) {
    mx = si = 0;
    X = V = 0;
    for (i = 1; i <= n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]), X += a[i];
    X /= n;
    for (i = 1; i <= n; i++) si += (a[i] == mx), V += (a[i] - X) * (a[i] - X);
    V /= n;
    if (V > 2.0 * X) {
      printf("uniform\n");
      continue;
    }
    if ((mx >= 3) && (mx * 3 <= si)) {
      printf("uniform\n");
      continue;
    }
    printf("poisson\n");
  }
  return 0;
}
