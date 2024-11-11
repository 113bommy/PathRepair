#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, v1, v2, k;
  scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
  int x = (n - 1) / k;
  double t = l / (2. * (double)x * (double)v2 / double(v1 + v2) + v2);
  double t_ = double(v2 - v1) / double(v1 + v2) * t;
  double T = (x + 1) * t + x * t_;
  printf("%.18f\n", T);
  return 0;
}
