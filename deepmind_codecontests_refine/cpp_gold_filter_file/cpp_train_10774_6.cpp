#include <bits/stdc++.h>
using namespace std;
int a[200009], n, times = 200;
double cal(double x) {
  double s_max = 0, s_min = 0, t_max = 0, t_min = 0;
  for (int i = 1; i <= n; i++) {
    t_max += (a[i] - x);
    t_min += (a[i] - x);
    s_max = max(s_max, t_max);
    s_min = min(s_min, t_min);
    if (t_max < 0) t_max = 0;
    if (t_min > 0) t_min = 0;
  }
  return max(s_max, -s_min);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  double l = -1e9, r = 1e9, mid, x, le, ri;
  while (times--) {
    le = l + (r - l) / 3;
    ri = r - (r - l) / 3;
    if (cal(ri) > cal(le))
      r = ri;
    else
      l = le;
  }
  printf("%.10f\n", cal(l));
}
