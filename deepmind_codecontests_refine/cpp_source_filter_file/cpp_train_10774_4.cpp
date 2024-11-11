#include <bits/stdc++.h>
using namespace std;
int N;
double a[200200], g[200200], l, r, LT, RT, ans;
double f(double x) {
  double weakness = 0;
  for (int i = 0; i < (N); i++) g[i] = a[i] - x;
  double sum = 0;
  for (int i = 0; i < (N); i++) {
    sum = max(sum, 0.0);
    sum += g[i];
    weakness = max(weakness, sum);
  }
  sum = 0;
  for (int i = 0; i < (N); i++) {
    sum = min(sum, 0.0);
    sum += g[i];
    weakness = max(weakness, -sum);
  }
  return weakness;
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < (N); i++) {
    scanf("%lf", &a[i]);
  }
  l = -1e9, r = 1e9;
  while (true) {
    if (abs(r - l) < 1e-8) {
      ans = (r + l) / 2.0;
      break;
    }
    LT = l + (r - l) / 3.0;
    RT = r - (r - l) / 3.0;
    if (f(LT) > f(RT)) {
      l = LT;
    } else {
      r = RT;
    }
  }
  printf("%.10lf\n", f(ans));
  return 0;
}
