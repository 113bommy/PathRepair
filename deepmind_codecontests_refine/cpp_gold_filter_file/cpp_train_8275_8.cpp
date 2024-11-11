#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, v;
  scanf("%d %d", &a, &v);
  int l, d, w;
  scanf("%d %d %d", &l, &d, &w);
  double ans;
  if (w >= v || w * w / 2.0 / a >= d) {
    double t1 = double(v) / a;
    double t2 = sqrt(2.0 * l / a);
    if (t1 > t2 + 1e-7) {
      ans = t2;
    } else {
      double remaining = l - 0.5 * a * t1 * t1;
      ans = t1 + remaining / v;
    }
  } else {
    double remaining = d - 0.5 * w * w / a;
    double time = (-2 * w + sqrt(4 * w * w + 4 * a * remaining)) / (2 * a);
    if (time * a + w + 1e-7 > v) {
      time = double(v - w) / a;
    }
    remaining -= (w + w + a * time) * time;
    ans = double(w) / a + time * 2 + remaining / (w + a * time);
    remaining = l - d;
    if ((v + w) * (v - w) / 2.0 / a + 1e-7 >= remaining) {
      time = (-2 * w + sqrt(4 * w * w + 8 * a * remaining)) / 2 / a;
      ans += time;
    } else {
      ans += double(v - w) / a;
      remaining -= double(w + v) * double(v - w) / a / 2;
      ans += remaining / v;
    }
  }
  printf("%.7lf\n", ans);
  return 0;
}
