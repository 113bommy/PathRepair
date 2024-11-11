#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  int n, a, d, ti, vi;
  double last = -1e10;
  scanf("%d%d%d", &n, &a, &d);
  double ta, tc, s;
  for (int(i) = 0; (i) < (n); ++(i)) {
    scanf("%d%d", &ti, &vi);
    ta = double(vi) / a;
    s = a * double(ta) * ta / 2.0;
    if (s - 1e-7 >= d) {
      tc = ti + pow(2 * d / double(a), 0.5);
    } else {
      s = vi * double(vi) / 2.0 / a;
      tc = ti + ta + (d - s) / vi;
    }
    tc = max(tc, last);
    printf("%.16lf\n", tc);
    last = tc;
  }
  return 0;
}
