#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double t = (double)d / (double)v;
  while (t >= (double)(g + r)) t -= (double)(g + r);
  if (t - (double)g >= 0) {
    printf("%.6f", ((double)l / double(v)) + (double)r - (t - (double)g));
  } else {
    printf("%.6f", (double)l / double(v));
  }
  return 0;
}
