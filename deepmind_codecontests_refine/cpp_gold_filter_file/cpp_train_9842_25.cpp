#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
  int d, h, v, e;
  scanf("%d %d", &d, &h);
  scanf("%d %d", &v, &e);
  double r = d / 2.0;
  double vr = M_PI * e * r * r;
  if (v + 1e-6 < vr) {
    printf("NO\n");
    return 0;
  }
  double vo = h * M_PI * r * r;
  double t = vo / (v - vr);
  printf("YES\n%.6f\n", t);
  return 0;
}
