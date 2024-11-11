#include <bits/stdc++.h>
int a, v;
int l, d, w;
double ans;
void setIO(void) { freopen("5d.in", "r", stdin); }
void input(void) {
  scanf("%d%d", &a, &v);
  scanf("%d%d%d", &l, &d, &w);
}
void process(void) {
  if (w >= v) {
    double v_max = sqrt(2 * a * l);
    double s1, s2;
    double t1, t2;
    if (v_max <= v) {
      t1 = v_max / a;
      t2 = 0;
    } else {
      t1 = (double)v / a;
      s1 = v * t1 / 2;
      t2 = (double)(l - s1) / v;
    }
    ans = t1 + t2;
    return;
  }
  double t1, t2, t3, t4, t5;
  double s1, s2, s3, s4, s5;
  double v_max;
  double pre_v;
  v_max = sqrt(d * 2 * a);
  if (v_max <= w) {
    t1 = v_max / a;
    t2 = 0;
    t3 = 0;
    pre_v = v_max;
  } else {
    v_max = sqrt((d * 2 * a + w * w) / 2);
    if (v_max <= v) {
      t1 = v_max / a;
      t2 = 0;
      t3 = (v_max - w) / a;
      pre_v = w;
    } else {
      t1 = (double)v / a;
      t3 = (double)(v - w) / a;
      double s1 = v * t1 / 2;
      double s3 = (v + w) * t3 / 2;
      double s2 = d - (s1 + s2);
      t2 = s2 / v;
      pre_v = w;
    }
  }
  double sr = l - d;
  double v_max2 = sqrt(sr * 2 * a + pre_v * pre_v);
  if (v_max2 <= v) {
    t4 = (v_max2 - pre_v) / a;
    t5 = 0;
  } else {
    t4 = (v - pre_v) / a;
    s4 = (v + pre_v) * t4 / 2;
    s5 = sr - s4;
    t5 = s5 / v;
  }
  ans = t1 + t2 + t3 + t4 + t5;
}
void output(void) { printf("%lf\n", ans); }
int main() {
  input();
  process();
  output();
}
