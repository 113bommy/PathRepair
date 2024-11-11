#include <bits/stdc++.h>
using namespace std;
int N;
int x[200000 + 5];
double pos[200000 + 5];
inline int f(double d) {
  double last = -1;
  int ret = 0;
  pos[0] = pos[1] = pos[2] = 0;
  for (int i = 0; i < N; i++) {
    if (x[i] > last + 1e-10) {
      last = x[i] + 2.0 * d;
      pos[ret] = last - d;
      ret++;
    }
  }
  return ret;
}
inline double bsearch() {
  double lo = 0.0;
  double hi = 1000111000.0;
  double mid;
  for (int k = 0; k < 100; k++) {
    mid = (lo + hi) * 0.5;
    if (f(mid) > 3) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return mid;
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &x[i]);
  }
  sort(x, x + N);
  double d = bsearch();
  printf("%.6lf\n", d);
  f(d);
  printf("%.6lf %.6lf %.6lf\n", pos[0], pos[1], pos[2]);
  return 0;
}
