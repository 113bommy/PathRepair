#include <bits/stdc++.h>
using namespace std;
double x;
int main() {
  double a, h;
  scanf("%lf", &x);
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      a = i;
      h = j;
      if ((fabs((((a * h / 2) / sqrt((a / 2) * (a / 2) + h * h))) - (x)) <=
           0.00001)) {
        printf("%d %d\n", i, j);
        return 0;
      }
    }
  }
  return 0;
}
