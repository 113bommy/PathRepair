#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
struct point {
  double x, y;
} p[N];
int n;
double w, v, u;
int judge(double x) {
  if (x > 1e-9) return 1;
  if (x < -1e-9) return -1;
  return 0;
}
bool judge_before() {
  for (int i = 0; i < n; i++) {
    if (judge(u * p[i].x - p[i].y * v) < 0) return false;
  }
  return true;
}
bool judge_after(double t) {
  for (int i = 0; i < n; i++) {
    if (judge(u * p[i].x - p[i].y * v - u * v * t) > 0) return false;
  }
  return true;
}
int main() {
  scanf("%d%lf%lf%lf", &n, &w, &v, &u);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
  }
  if (judge_before()) {
    printf("%.10lf\n", w / u);
    return 0;
  }
  double l = 0, r = 1e9, mid;
  for (int i = 0; i < 100; i++) {
    mid = (l + r) / 2;
    if (judge_after(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf\n", w / u + (l + r) / 2);
  return 0;
}
