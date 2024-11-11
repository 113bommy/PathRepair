#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  double rez = 1.0 * a * a * a * 1.41421356237309 / 12.0;
  rez += 1.0 * b * b * b * 1.41421356237309 / 6.0;
  rez += 1.0 * c * c * c * 7.23606797749978 / 24.0;
  printf("%.7lf\n", rez);
  return 0;
}
