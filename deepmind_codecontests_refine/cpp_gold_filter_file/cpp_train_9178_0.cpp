#include <bits/stdc++.h>
int main() {
  float h, l, d;
  scanf("%f%f", &h, &l);
  d = (l * l - h * h) / (2 * h);
  printf("%.12f\n", d);
}
