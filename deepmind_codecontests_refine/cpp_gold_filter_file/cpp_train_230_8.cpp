#include <bits/stdc++.h>
using namespace std;
double PI = 3.14159265358979323846264338327;
pair<double, double> f(int N, double ang) {
  double L = 0, R = 0, H = 0;
  double x = 0, y = 0;
  for (int i = 0; i < 2 * N; i++) {
    x += cos(ang + PI * i / N);
    y += sin(ang + PI * i / N);
    R = max(R, x);
    L = min(L, x);
    H = max(H, y);
  }
  return {R - L, H};
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    double l = 0, r = PI / N / 2;
    while (abs(r - l) > 0.0000001) {
      double mid = (l + r) / 2;
      auto res = f(N, mid);
      if (res.second < res.first)
        l = mid;
      else
        r = mid;
    }
    printf("%.15lf\n", f(N, l).first);
  }
  return 0;
}
