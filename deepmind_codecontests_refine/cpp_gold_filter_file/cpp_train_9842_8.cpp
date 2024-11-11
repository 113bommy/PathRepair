#include <bits/stdc++.h>
int main(void) {
  int d, h, v, e;
  double r, A, V, vh, eh, t, pi = 3.1415926535;
  scanf("%d %d %d %d", &d, &h, &v, &e);
  r = d / 2.0;
  A = pi * r * r;
  V = A * h;
  vh = v / A;
  eh = e * 1.0;
  if (vh <= eh) {
    printf("NO");
  } else {
    t = h / (vh - eh);
    printf("YES\n%0.6lf", t);
  }
  return 0;
}
