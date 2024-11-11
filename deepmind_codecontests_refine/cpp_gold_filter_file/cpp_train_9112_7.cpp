#include <bits/stdc++.h>
using namespace std;
const int inf = 1999999999;
const double pi = acos(-1.0);
const double eps = 1e-10;
char gc() {
  char c;
  while (isspace(c = getchar()))
    ;
  return c;
}
int main() {
  int n, k;
  double tn[10000];
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lf", &tn[i]);
  double low = 0, high = 1E10, mid;
  for (int i = 0; i < 100; i++) {
    mid = (low + high) / 2;
    double s = 0, s2 = 0;
    for (int j = 0; j < n; j++) {
      if (tn[j] < mid - eps)
        s2 += mid - tn[j];
      else if (tn[j] > mid)
        s += (tn[j] - mid) * (100 - k) / 100.;
    }
    if (s2 <= s + eps)
      low = mid;
    else
      high = mid;
  }
  mid = (low + high) / 2;
  printf("%.7f\n", mid);
}
