#include <bits/stdc++.h>
int main() {
  double a, b, i, j;
  char ch;
  scanf("%lf %c %lf", &a, &ch, &b);
  if (a >= 12) {
    a = a - 12;
  }
  i = ((360 / 12) * a) + ((b * 360) / (60 * 12));
  j = (360 * b) / 60;
  printf("%lf %lf", i, j);
}
