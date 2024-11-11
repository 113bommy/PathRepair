#include <bits/stdc++.h>
using namespace std;
int n, h;
char op[110];
double ans, pw[110];
int main() {
  scanf("%s", op);
  scanf("%d%d", &n, &h);
  if (op[0] == 'A') {
    pw[0] = 1.;
    for (int i = 1; i <= 70; i++) pw[i] = pw[i - 1] * .5;
    for (int i = 1; i <= h; i++) {
      double nm = 1. - pw[i], nm_ = 1.;
      for (int j = 1; j < n; j++, nm_ *= nm) {
        double p0 = (n - j) * nm_ * pw[i * 2];
        double v =
            (1. / pw[i]) - (1. / pw[i - 1]) * (1 + (j - 1) * (1. / pw[i] - 1));
        ans += v * p0;
      }
    }
    ans += n;
    printf("%.9lf\n", ans);
  } else
    printf("%d\n", n);
}
