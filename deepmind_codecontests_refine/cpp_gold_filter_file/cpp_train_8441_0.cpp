#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
};
Point pnt[2005];
int n, pos, some;
long long ans;
double tmp[2005], pi = acos(-1.0);
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    scanf("%lf%lf", &pnt[i].x, &pnt[i].y);
  }
  for (register int i = 1; i <= n; i++) {
    some = 0;
    for (register int j = 1; j <= n; j++) {
      if (i == j) {
        continue;
      }
      some++;
      tmp[some] = atan2(pnt[j].y - pnt[i].y, pnt[j].x - pnt[i].x);
    }
    sort(tmp + 1, tmp + some + 1);
    pos = 1;
    for (register int j = 1; j <= some; j++) {
      if (tmp[j] > 0) {
        break;
      }
      while (pos <= some && tmp[pos] - tmp[j] < pi) {
        pos++;
      }
      ans += (1ll * (pos - j - 2) * (pos - j - 1) * (some - pos + j) *
              (some - pos + j - 1)) >>
             2;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
