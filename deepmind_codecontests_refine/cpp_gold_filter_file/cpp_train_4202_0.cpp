#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, m;
  int vx, vy, vz;
  scanf("%d%d%d", &a, &b, &m);
  scanf("%d%d%d", &vx, &vy, &vz);
  a *= -2 * vy;
  b *= -2 * vy;
  m *= 2;
  int a_curr = a / 2;
  int b_curr = 0;
  a_curr += vx * m;
  b_curr += vz * m;
  while (a_curr < 0 || a_curr > a)
    if (a_curr < 0)
      a_curr *= -1;
    else
      a_curr = a + a - a_curr;
  while (b_curr < 0 || b_curr > b)
    if (b_curr < 0)
      b_curr *= -1;
    else
      b_curr = b + b - b_curr;
  printf("%.10f %.10f\n", -double(a_curr) / 2 / vy, -double(b_curr) / 2 / vy);
  return 0;
}
