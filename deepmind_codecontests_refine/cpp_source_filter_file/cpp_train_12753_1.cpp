#include <bits/stdc++.h>
int main() {
  float l, q, p, t;
  scanf("%f %f %f", &l, &q, &p);
  t = l / (q + p);
  l = p * t;
  printf("%.1f", l);
  return 0;
}
