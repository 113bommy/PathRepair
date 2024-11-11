#include <bits/stdc++.h>
int a, b, c, i, j, s, f, X;
double k, ans1, ans2, p, q, h;
double mini(double XX, double YY) { return XX < YY ? XX : YY; }
int main() {
  scanf("%d%d%d", &a, &b, &c);
  for (i = 0; i < a; i++) {
    scanf("%d%d", &s, &f);
    k = (double)(f - s) / 2 / (double)b;
    X = 50;
    p = 0.0;
    q = 2000000000.0;
    while (X--) {
      h = (p + q) / 2;
      if (h - sin(h) > k) {
        q = h;
      } else {
        p = h;
      }
    }
    ans1 = p;
    X = 50;
    p = 0.0;
    q = 2000000000.0;
    while (X--) {
      h = (p + q) / 2;
      if (h + sin(h) > k) {
        q = h;
      } else {
        p = h;
      }
    }
    ans2 = p;
    ans1 = mini(ans1, ans2);
    printf("%.12lf\n", ans1 * 2 / (double)c * (double)b);
  }
}
