#include <bits/stdc++.h>
using namespace std;
int re() {
  int ret = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f = (ch == '-') ? -f : f, ch = getchar();
  while (isdigit(ch)) ret = ret * 10 + ch - '0', ch = getchar();
  return ret * f;
}
const double pi = acos(-1);
double len, angle, delta, x, y;
signed main() {
  int n = re();
  if (n < 5) {
    puts("No solution");
    return 0;
  }
  len = 300, delta = pi - (n - 2) * pi / (1.0 * n);
  puts("0 0");
  for (int i = 2; i < n; ++i) {
    angle += delta;
    x += len * cos(angle), y += len * sin(angle);
    printf("%lf %lf\n", x, y);
    len += 0.01;
  }
  len = y / sin(delta);
  printf("%lf 0\n", x + len * cos(delta));
  return 0;
}
