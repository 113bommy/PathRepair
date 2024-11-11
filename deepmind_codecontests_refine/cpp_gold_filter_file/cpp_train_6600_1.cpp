#include <bits/stdc++.h>
double a, b, c, d;
double t, l;
int gcd(int x, int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
int main() {
  int z = 0;
  scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
  if (a / b == c / d) {
    printf("0/1\n");
    exit(0);
  }
  if (a / c < b / d) {
    t = b * c;
    l = b * c - a * d;
  } else {
    t = a * d;
    l = a * d - b * c;
  }
  int g = gcd(int(t), int(l));
  printf("%.0lf/%.0lf\n", l / g, t / g);
}
