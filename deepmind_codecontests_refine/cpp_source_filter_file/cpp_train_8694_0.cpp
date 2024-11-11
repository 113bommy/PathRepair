#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double x = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
  double y = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
  if (x < y) swap(x, y);
  printf("%.20f\n%.20f\n", x, y);
  return 0;
}
