#include <bits/stdc++.h>
using namespace std;
int x[500005], v[500005];
int main() {
  memset(x, 0, sizeof(x));
  memset(v, 0, sizeof(v));
  int n = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &v[i]);
  }
  int num = 100;
  double l = 0, r = 1000000007;
  while (num--) {
    double mid = (l + r) / 2.0, maxR = -1e20;
    bool tag = false;
    for (int i = 0; i < n; ++i) {
      if (v[i] > 0) {
        maxR = max(maxR, x[i] + v[i] * mid);
      } else {
        if (x[i] + v[i] * mid <= maxR) {
          tag = true;
          break;
        }
      }
    }
    if (tag) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (l > 1000000000) {
    printf("-1.0000000000000000\n");
  } else {
    printf("%.10lf\n", l);
  }
  return 0;
}
