#include <bits/stdc++.h>
using namespace std;
char s[10];
int n, h;
int main() {
  scanf("%s", s + 1);
  scanf("%d%d", &n, &h);
  if (s[1] == 'B') {
    printf("%.12lf\n", n);
    return 0;
  }
  double ans = n;
  double mi = 1;
  for (int i = 1; i <= h; i++) {
    mi *= 2;
    double t = 1;
    for (int j = 1; j <= n; j++) {
      ans += (n - j) * 1.0 / (mi * mi) * t *
             (mi - mi / 2.0 * (1.0 + (j - 1) / (mi - 1)));
      t *= (1.0 - 1.0 / mi);
    }
  }
  printf("%.12lf\n", ans);
}
