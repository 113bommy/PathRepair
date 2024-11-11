#include <bits/stdc++.h>
using namespace std;
int a, w, h, t, p;
double x;
int gcd(int u, int v) { return u % v == 0 ? v : gcd(v, u % v); }
int main() {
  scanf("%d%d%d", &a, &h, &w);
  h += a, w += a, t = gcd(h, w);
  if (t <= a || h < a + a || w < a + a)
    printf("-1");
  else {
    p = t / a;
    x = t * 1.0000000000 / p - a, printf("%lf", x);
  }
  return 0;
}
