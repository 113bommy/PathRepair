#include <bits/stdc++.h>
int main() {
  float l, q, p, t;
  scanf("%f %f %f", &l, &p, &q);
  t = l / (q + p);
  l = p * t;
  printf("%f", l);
  return 0;
}
