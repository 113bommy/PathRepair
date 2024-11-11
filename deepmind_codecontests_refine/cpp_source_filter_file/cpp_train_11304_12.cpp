#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  scanf("%d", &t);
  double r, a, b;
  for (i = 0; i < t; i++) {
    cin >> a >> b;
    if (a < 0.5) {
      if (b < 0.5)
        printf("0.500\n");
      else
        printf("1.000\n");
      continue;
    }
    if (a >= 4 * b)
      r = 0.5 + 0.5 * (1 - 2 * b / a);
    else {
      r = (2 * b - 2 * b * (1 - (a / (4 * b))) * (1 - (a / (4 * b))));
      r = 0.5 + 0.5 * (1 - r / a);
    }
    printf("%.9lf\n", r);
  }
  return 0;
}
