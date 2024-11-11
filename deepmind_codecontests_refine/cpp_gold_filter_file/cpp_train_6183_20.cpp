#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double t = d / v;
  double tm = fmod(t, g + r);
  if (tm >= g) t += g + r - tm;
  t += (l - d) / v;
  printf("%.17lf\n", t);
  return 0;
}
