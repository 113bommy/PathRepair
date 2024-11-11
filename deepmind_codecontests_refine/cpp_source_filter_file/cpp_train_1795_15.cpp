#include <bits/stdc++.h>
double f(double t) { return sqrt(fabs(t)) + 5 * pow(t, 3); }
int main(void) {
  int a[11];
  double y;
  int i;
  for (i = 0; i < 11; i++) scanf("%d", &a[i]);
  for (i = 10; i >= 0; i--) {
    y = f(a[i]);
    if (y > 400)
      printf("f(%d) = MAGNA NIMIS!\n", i);
    else
      printf("f(%d) = %.2f\n", a[i], y);
  }
  return 0;
}
