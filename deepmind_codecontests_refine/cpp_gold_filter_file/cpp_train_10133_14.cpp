#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, d;
  scanf("%d", &n);
  scanf("%d", &a);
  scanf("%d", &d);
  double time[n];
  int t, v;
  scanf("%d", &t);
  scanf("%d", &v);
  double t1 = (double)v / a;
  double t2;
  double dis = (double)0.5 * a * t1 * t1;
  if (dis < d)
    t2 = ((double)d - dis) / v;
  else {
    t1 = (double)sqrt((double)2 * d / a);
    t2 = 0.0;
  }
  time[0] = t + t1 + t2;
  for (int i = 1; i < n; i++) {
    t1 = 0;
    t2 = 0;
    scanf("%d", &t);
    scanf("%d", &v);
    t1 = (double)v / a;
    dis = (double)a * t1 * t1 / 2;
    if (dis < d)
      t2 = ((double)d - dis) / v;
    else {
      t1 = (double)sqrt((double)2 * d / a);
      t2 = 0;
    }
    time[i] = max(t + t1 + t2, time[i - 1]);
  }
  for (int i = 0; i < n; i++) printf("%.10lf\n", time[i]);
  return 0;
}
