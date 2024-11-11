#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, g, v, d, r;
  cin >> l >> d >> v >> g >> r;
  double time = (d / (v * (g + r))) * (g + r);
  d = d - d / (v * (g + r));
  double tt = d / (v * 1.0);
  if (tt >= g) {
    time = time + g + r;
  } else {
    time = time + tt;
  }
  time += (l - d) / (v * 1.0);
  printf("%.9f\n", time);
}
