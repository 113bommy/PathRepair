#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    a /= 4;
    double prob = 0.0f;
    if (a >= b) {
      if (a != 0)
        prob = (a - b) / a + 0.5 * b / a;
      else
        prob = 1.0f;
    } else {
      if (b != 0)
        prob = 0.5 * a / b;
      else
        prob = 0.0;
    }
    prob = 0.5f + prob / 2;
    printf("%.10lf\n", prob);
  }
  return 0;
}
