#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, d, v;
  int g, r;
  cin >> l >> d >> v >> g >> r;
  double tot = 0;
  int first = d / v;
  double wait = 0;
  while (true) {
    wait++;
    if (first < g) {
      printf("%.7f\n", l / v);
      return 0;
    }
    first -= g;
    if (first < r) {
      printf("%.7f\n", (wait * (g + r)) + (l - d) / v);
      return 0;
    }
    first -= r;
  }
  return 0;
}
