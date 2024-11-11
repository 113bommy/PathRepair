#include <bits/stdc++.h>
using namespace std;
double all[100005];
int main() {
  int a = 0, b = 0, T, N, M, i;
  double l = 0.0, r, t = 0, x, y, tt;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &N, &M);
    l = 0.0;
    r = (double)M;
    a = 0;
    b = N - 1;
    x = 1.0;
    y = 1.0;
    tt = 0.0;
    for (i = 0; i < N; i++) scanf("%lf", &all[i]);
    while (1) {
      t = min((all[a] - l) / x, (r - all[b]) / y);
      l += x * t;
      r -= y * t;
      tt += t;
      if (abs(l - all[a]) <= 1e-6) {
        a++;
        x++;
      }
      if (abs(r - all[b]) <= 1e-6) {
        b--;
        y++;
      }
      if (a >= b) {
        tt += (r - l) / (x + y);
        break;
      }
    }
    printf("%.6lf\n", tt);
  }
  return 0;
}
