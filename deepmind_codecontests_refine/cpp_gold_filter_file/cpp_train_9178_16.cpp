#include <bits/stdc++.h>
int main() {
  int h, l;
  float a;
  scanf("%d %d", &h, &l);
  a = l * tan(atan(1.0 * h / l) - atan(1.0 * l / h));
  if (a < 0) a = -a;
  printf("%.10f", a);
  return 0;
}
