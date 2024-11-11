#include <bits/stdc++.h>
using namespace std;
int i, j, k, h, w, a, g, t;
double ans;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  scanf("%d%d%d", &a, &h, &w);
  if (h < a || w < a) return puts("-1"), 0;
  g = gcd(h + a, w + a);
  if (g < a) return puts("-1"), 0;
  t = g / a;
  printf("%.9lf\n", 1.0 * g / (1.0 * t) - 1.0 * a);
}
