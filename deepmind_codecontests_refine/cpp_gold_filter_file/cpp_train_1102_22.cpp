#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  double a, b;
  scanf("%d", &t);
  while (t--) {
    scanf("%lf%lf", &a, &b);
    if (b == 0)
      printf("1\n");
    else if (a == 0) {
      printf("0.5000\n");
    } else if (a <= b * 4) {
      printf("%.12lf\n", (double)(b + (a / 8.0)) / (double)(2.0 * b));
    } else {
      printf("%.12lf\n", (double)(a - b) / (double)a);
    }
  }
}
