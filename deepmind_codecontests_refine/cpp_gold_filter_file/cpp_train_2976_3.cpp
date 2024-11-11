#include <bits/stdc++.h>
using namespace std;
struct device {
  double a, b;
} v[100000 + 5];
int n;
double p;
bool valid(double t) {
  double charging_time = 0, x;
  for (int i = 1; i <= n; i++) {
    x = (-v[i].b + v[i].a * (double)t) / p;
    if (x < 0) x = 0;
    charging_time += x;
    if (charging_time > t) return false;
  }
  return true;
}
double cb(double st, double dr) {
  double mij, last = -1;
  while (dr - st >= 0.00001 && st <= dr) {
    mij = (st + dr) / 2;
    if (valid(mij)) {
      st = mij + 0.00001 / 10;
      last = mij;
    } else
      dr = mij - 0.00001 / 10;
  }
  return last;
}
int main() {
  double st, dr;
  long long sa = 0;
  scanf("%d %lf", &n, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%lf %lf", &v[i].a, &v[i].b);
    sa += (int)v[i].a;
  }
  if (p >= sa) {
    printf("-1");
    return 0;
  }
  st = 0;
  dr = 100000000000;
  printf("%f", cb(st - 2 * 0.00001, dr));
  return 0;
}
