#include <bits/stdc++.h>
const double eps = 1e-8;
using namespace std;
double v1[209], v2[209];
int hp1, hp2, dt1, dt2, l1, l2, r1, r2, p1, p2, t1, t2;
bool attack(double v[], int l, int r, int p, int hp) {
  bool flag = 0;
  for (int i = 1; i <= hp; i++) {
    if (v[i] < eps) continue;
    flag = 1;
    double add = (1 - p * 0.01) * v[i] / (r - l + 1);
    v[i] *= p * 0.01;
    for (int x = l; x <= r; x++) v[max(i - x, 0)] += add;
  }
  return flag;
}
int main() {
  double ans = 0;
  cin >> hp1 >> dt1 >> l1 >> r1 >> p1;
  cin >> hp2 >> dt2 >> l2 >> r2 >> p2;
  if (p1 == 100)
    return printf("0"), 0;
  else if (p2 == 100)
    return printf("1"), 0;
  v1[hp1] = 1;
  v2[hp2] = 1;
  while (1)
    if (t1 <= t2) {
      t1 += dt1;
      v2[0] = 0;
      attack(v2, l1, r1, p1, hp1);
      ans += (1 - v1[0]) * v2[0];
    } else {
      t2 += dt2;
      if (!attack(v1, l2, r2, p2, hp2)) break;
    }
  printf("%.10f\n", ans);
  return 0;
}
