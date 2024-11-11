#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r, v;
  int s, f;
  double dis, t, tem, l, u;
  while (scanf("%d%d%d", &n, &r, &v) != EOF) {
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &s, &f);
      dis = f - s;
      t = dis / (2 * 3.1415926 * r);
      tem = dis - t * 2 * 3.1415926 * r;
      l = 0;
      u = 2 * 3.1415926;
      while (l + 1e-15 < u) {
        double mid = (l + u) / 2;
        if (2 * sin(mid / 2) * r + mid * r < tem) {
          l = mid;
        } else {
          u = mid;
        }
      }
      double len = t * 2 * 3.1415926 * r + u * r;
      printf("%.12f\n", len / v);
    }
  }
  return 0;
}
