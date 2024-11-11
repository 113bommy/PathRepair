#include <bits/stdc++.h>
using namespace std;
int main() {
  int S, a, b, c;
  double x, y, z, k;
  scanf("%d %d %d %d", &S, &a, &b, &c);
  if (a == 0 && b == 0 && c == 0) {
    printf("%d %d %d", S, 0, 0);
    return 0;
  }
  k = a + b + c;
  x = a / k * S;
  y = b / k * S;
  z = c / k * S;
  printf("%.15lf %.15lf %.15lf", x, y, z);
  return 0;
}
