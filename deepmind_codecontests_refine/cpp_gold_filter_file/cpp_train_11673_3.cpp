#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, h, t;
  double sum = 0.0, nsum = 1.0, s = 0.0, s2 = 0.0;
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &t);
    s += t;
    if (i == h) s2 = t;
  }
  if (n > s) {
    printf("-1.0");
    return 0;
  }
  if (n > s - s2 + 1) {
    printf("1.0");
    return 0;
  }
  s--;
  s2--;
  double ff, fff;
  for (int i = 0; i < n - 1; i++) {
    sum += nsum * s2 / s;
    ff = s2 / s, fff = 1 - s2 / s;
    nsum *= (1 - s2 / s);
    s--;
  }
  printf("%.10lf", sum);
  return 0;
}
