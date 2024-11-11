#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int OO = INT_MAX;
int main() {
  double l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double t = d / v;
  double tm = remainder(t, g + r);
  if (tm >= g) t += g + r - tm;
  t += (l - d) / v;
  printf("%.7lf\n", t);
  return 0;
}
