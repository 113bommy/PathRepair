#include <bits/stdc++.h>
#pragma warning(disable : 4996);
using namespace std;
int H, L;
double l, r;
double x, y;
int main() {
  while (~scanf("%d%d", &H, &L)) {
    l = (L * L - H * H) / 2 / H;
    r = l + 1;
    x = (l + r) / 2.;
    while (r - l >= 1e-7) {
      if (2 * x * H <= L * L - H * H) l = x;
      if (2 * x * H >= L * L - H * H) r = x;
      x = (l + r) / 2.;
    }
    printf("%.8f\n", x);
  }
  return 0;
}
