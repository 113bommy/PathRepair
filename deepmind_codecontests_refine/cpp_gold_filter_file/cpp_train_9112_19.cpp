#include <bits/stdc++.h>
using namespace std;
int n, k, s[10005];
bool ok(double m) {
  double bal = 0;
  for (int i = (1); i <= (n); i++) {
    if (s[i] > m)
      bal += (s[i] - m) * (1 - k / 100.0);
    else
      bal += (s[i] - m);
  }
  return bal > 0;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (1); i <= (n); i++) scanf("%d", &s[i]);
  double l = 0, r = 1001;
  for (int i = (1); i <= (60); i++) {
    double m = (l + r) / 2;
    if (ok(m))
      l = m;
    else
      r = m;
  }
  printf("%.10lf\n", l);
  return 0;
}
