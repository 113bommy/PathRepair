#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int n, k;
double l, v1, v2;
int main() {
  scanf("%d %lf %lf %lf %d", &n, &l, &v1, &v2, &k);
  double m(floor((double)n / (double)k));
  double s((v2 - v1) / (v2 + v1));
  double t1(l / (v2 + v1 * (m - 1) * (1 + s)));
  double t2(s * t1);
  printf("%.6f\n", t1 * m + t2 * (m - 1.));
  return 0;
}
