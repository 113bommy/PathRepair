#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, a, d, ti, vi;
  scanf("%ld%ld%ld", &n, &a, &d);
  double s, acc, t, p, vel, min = 0, disp;
  for (int i = 0; i < n; i++) {
    scanf("%ld%ld", &ti, &vi);
    acc = a;
    vel = vi;
    s = d;
    if ((vel * vel) / (2.0 * acc) > s)
      t = sqrt(((2 * s) / acc));
    else
      t = (vel / acc) + ((s - ((vel * vel) / (2.0 * acc))) / vel);
    if (i == 0) {
      printf("%.10lf\n", t + ti);
      min = t + ti;
    } else {
      if (ti + t <= min) {
        printf("%.10lf\n", min);
      } else {
        printf("%.10lf\n", t + ti);
        min = t + ti;
      }
    }
  }
  return 0;
}
