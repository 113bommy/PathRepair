#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d%d", &a, &b);
    double p;
    if (a == 0 && b == 0) {
      p = 1;
    } else if (a == 0) {
      p = 0.5;
    } else if (b == 0) {
      p = 1;
    } else if (4 * b >= a) {
      p = (b + b + a / 4.0) / (4.0 * b);
    } else {
      p = 1 - b * 1.0 / a;
    }
    printf("%.8lf\n", p);
  }
  return 0;
}
