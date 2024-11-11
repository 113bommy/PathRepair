#include <bits/stdc++.h>
using namespace std;
int a, w, h;
int gcd(int x, int y) { return x ? gcd(y % x, x) : y; }
int main() {
  int g, q, t;
  cin >> a >> w >> h;
  g = gcd(w + a, h + a);
  t = (w + a) / g;
  q = ((w / a + 1) / t) * t - 1;
  if (q < 0)
    printf("-1");
  else
    printf("%.9lf", 1.0 * (w + a) / (q + 1) - a);
  return 0;
}
