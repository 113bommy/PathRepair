#include <bits/stdc++.h>
using namespace std;
int main() {
  double dd, sc;
  int i, b, a, d, cnt;
  for (scanf("%d", &cnt); cnt--;) {
    b = d = 0;
    for (i = 0; i < 250; i++) {
      scanf("%d", &a);
      if (b < abs(a)) b = abs(a);
      d += a * a;
    }
    dd = 1.0 * d / 250;
    sc = dd / (b * b);
    if (sc < 0.25)
      puts("poisson");
    else
      puts("uniform");
  }
}
