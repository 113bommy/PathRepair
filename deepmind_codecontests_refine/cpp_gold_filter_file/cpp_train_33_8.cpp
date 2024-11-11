#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, d;
  cin >> a >> b >> c;
  d = b * b - 4 * a * c;
  if (a == 0 && b == 0 && c == 0)
    printf("-1\n");
  else if (a == 0 && b == 0 && c != 0)
    printf("0\n");
  else if (a == 0)
    printf("1\n%f\n", -(c / b));
  else if (d < 0)
    printf("0\n");
  else if (d == 0)
    printf("1\n%.9f\n", -b / (2 * a));
  else if (a > 0)
    printf("2\n%.9f\n%.9f\n", (-b - sqrt(d)) / 2 / a, (-b + sqrt(d)) / (2 * a));
  else
    printf("2\n%.9f\n%.9f\n", (-b + sqrt(d)) / 2 / a, (-b - sqrt(d)) / (2 * a));
  return 0;
}
