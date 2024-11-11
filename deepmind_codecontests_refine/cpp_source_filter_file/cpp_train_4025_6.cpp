#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, hh, mm, H, D, C, N;
  cin >> hh >> mm;
  cin >> H >> D >> C >> N;
  double num1 = ceil(1.0 * H / N) * C;
  int t = (19 - hh) * 60 + 60 - mm;
  if (hh >= 20) t = 0;
  double num2 = 0.8 * ceil(1.0 * (H + D * t) / N) * C;
  printf("%.4lf\n", max(num1, num2));
  return 0;
}
