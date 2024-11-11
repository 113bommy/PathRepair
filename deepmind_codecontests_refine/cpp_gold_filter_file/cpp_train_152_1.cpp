#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const double eps = 1e-7;
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  double Max = 0, Min = 1, now;
  double l = -1e4, r = 1e4;
  while (fabs(Max + Min) > eps) {
    double m = (l + r) / 2;
    now = 0;
    Max = -1e9;
    for (int i = 0; i < n; i++) {
      now += a[i] - m;
      if (now > Max) Max = now;
      if (now < 0) now = 0;
    }
    now = 0;
    Min = 1e9;
    for (int i = 0; i < n; i++) {
      now += a[i] - m;
      if (now < Min) Min = now;
      if (now > 0) now = 0;
    }
    if (Max + Min > 0)
      l = m;
    else
      r = m;
  }
  printf("%.10f", Max);
  return 0;
}
