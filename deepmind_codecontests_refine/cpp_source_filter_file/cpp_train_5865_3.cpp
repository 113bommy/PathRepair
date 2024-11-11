#include <bits/stdc++.h>
#pragma comment(linker, "/stack:10000000")
using namespace std;
const int maxn = 100500;
const double eps = 1e-8;
double a[5 * maxn];
double ans[maxn];
int main() {
  int n, i, l, v1, v2, w;
  scanf("%d%d%d%d", &n, &l, &v1, &v2);
  double z = double(l) * double(v2) / double(v1 + v2);
  for ((i) = 0; (i) < (n); (i)++) {
    scanf("%d", &w);
    a[i] = double(w);
  }
  for (i = n; i < 5 * n; i++) a[i] = a[i - n] + l * 2;
  double curl = 0, curr = z;
  int pl = -1, pr = 9;
  for ((i) = 0; (i) < (n * 2); (i)++)
    if (a[i] - eps > z) {
      pr = i;
      break;
    }
  pr--;
  int x;
  while (pl < n && curl < 2 * l) {
    if (a[pl + 1] - curl < a[pr + 1] - curr) {
      x = pr - pl;
      if (a[pl + 1] > 2 * l + eps) {
        ans[pr - pl] += (2 * l - curl) / (2 * l);
        break;
      }
      ans[x] += (a[pl + 1] - curl) / (2 * l);
      curl = a[pl + 1];
      curr = curl + z;
      pl++;
    } else {
      x = pr - pl;
      if (a[pr + 1] - z > 2 * l + eps) {
        ans[pr - pl] += (2 * l - curl) / (2 * l);
        break;
      }
      ans[x] += (a[pr + 1] - curr) / (2 * l);
      curr = a[pr + 1];
      curl = curr - z;
      pr++;
    }
  }
  for ((i) = 0; (i) < (n + 1); (i)++) printf("%.8lf\n", ans[i]);
  return 0;
}
