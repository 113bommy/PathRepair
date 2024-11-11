#include <bits/stdc++.h>
using namespace std;
const int eps = 1e-7;
double maxn = -9999, minn = 1e7;
struct shiki {
  double x, y;
  double t1, t2;
};
int main() {
  double m, n, cv, pv;
  while (scanf("%lf%lf%lf%lf", &n, &m, &cv, &pv) != EOF) {
    shiki a;
    while (n--) {
      scanf("%lf%lf", &a.x, &a.y);
      minn = min(minn, a.x - (a.y / pv * cv));
      maxn = max(maxn, a.x - (a.y / pv * cv));
    }
    if (minn >= -eps)
      printf("%.10lf\n", m / pv);
    else if (maxn >= -eps)
      printf("%.10lf\n", m / pv + maxn / cv);
    else
      printf("%.10lf\n", m / pv);
  }
  return 0;
}
