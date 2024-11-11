#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
A cvt(B x) {
  stringstream ss;
  ss << x;
  A y;
  ss >> y;
  return y;
}
int n, k;
int y[300][301];
double s[300];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(k + 1); j++) scanf("%d", &y[i][j]);
  }
  for (int j = 0; j < (int)(k); j++) {
    for (int d = 0; d < (int)(2000); d++) {
      double m = 0;
      for (int i = 0; i < (int)(n); i++) {
        double yi = y[i][j] + (d + 0.5) / 2000 * (y[i][j + 1] - y[i][j]);
        s[i] += max(yi - m, 0.0) / 2000;
        m = max(m, yi);
      }
    }
  }
  for (int i = 0; i < (int)(n); i++) {
    printf("%.9f\n", s[i]);
  }
  return 0;
}
