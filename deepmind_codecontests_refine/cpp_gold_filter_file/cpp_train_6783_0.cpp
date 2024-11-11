#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int a[200010];
double calc(int d1, int d2) { return 2 * atan(1.0 / max(d1, d2)); }
int main() {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) scanf("%d", a + i + 1);
  a[0] = -1e9;
  a[n + 1] = 2e9;
  int m, p = 1;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    double ans = 0;
    while (a[p] < t) p++;
    int d1 = a[p] - t, d2 = t - a[p - 1] - 1;
    int d0 = min(d1, d2);
    if (!d0) {
      ans = PI;
      if (d1 || d2) ans /= 2;
    } else {
      ans = max(ans, atan(1.0 / d0));
      int pl = p - 1, pr = p;
      while (1) {
        int dl = t - a[pl] - 1, dr = a[pr] - t;
        if (dr > 2 * (d0 + 5) || dl > 2 * (d0 + 5)) break;
        if (abs(dl - dr) <= 1) {
          ans = max(ans, calc(dl, dr));
          break;
        }
        if (dl < dr)
          pl--;
        else
          pr++;
      }
    }
    printf("%.10f\n", ans);
  }
  return 0;
}
