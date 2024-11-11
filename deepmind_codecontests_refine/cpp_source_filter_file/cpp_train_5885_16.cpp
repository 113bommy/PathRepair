#include <bits/stdc++.h>
using namespace std;
double l1, l2, l3, h1, h2, h3, s1, s2, s3, t, v1, v2, v3, r;
const double Pi = acos(-1.0);
int main() {
  cin >> l1 >> l2 >> l3;
  s2 = l2 * l2;
  h2 = sqrt(l2 * l2 / 2);
  v2 = s2 * h2 / 3;
  s1 = l1 * l1 * sqrt(3) / 4;
  h1 = sqrt(l1 * l1 * 2 / 3);
  v1 = s1 * h1 / 3;
  s3 = 5 * l3 * l3 / 4 * 1 / tan(Pi / 5);
  r = sqrt(sqrt(5) + 5) / sqrt(10) * l3;
  h3 = sqrt(l3 * l3 - r * r);
  v3 = s3 * h3 / 3;
  printf("%.7f", v1 + v2 + v3);
  return 0;
}
