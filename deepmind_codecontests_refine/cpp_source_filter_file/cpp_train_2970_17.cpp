#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r;
  double ans;
  scanf("%d%d", &n, &r);
  double j1 = acos(-1.0) / n / 2;
  double j2 = acos(-1.0) / n;
  double j3 = acos(-1.0) - j1 - j2;
  double a = r * 1.0, b = a / sin(j3) * sin(j2);
  printf("%.10f\n", a * b * sin(j1) * 7);
  return 0;
}
