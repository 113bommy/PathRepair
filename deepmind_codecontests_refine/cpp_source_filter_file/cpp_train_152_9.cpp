#include <bits/stdc++.h>
using namespace std;
int s[204800], n;
double f(double x) {
  double l = 0, h = 0;
  for (int i = 1; i <= n; ++i) {
    l = min(l, i * x - s[i]);
    h = max(h, i * x - s[i]);
  }
  return h - l;
}
int main() {
  scanf("%d", &n);
  double L = 9e9, R = -9e9, t;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", s + i);
    s[i] += s[i - 1];
    t = s[i];
    t /= i;
    L = min(t, L);
    R = max(t, R);
  }
  for (int tm = 60; tm--;) {
    double M1 = (L * 2 + R) / 3, M2 = (L + R * 2) / 3;
    if (f(M1) < f(M2))
      R = M2;
    else
      L = M1;
  }
  printf("%.9lf\n", f(ldexp(L + R, -1)));
}
