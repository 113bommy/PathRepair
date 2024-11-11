#include <bits/stdc++.h>
using namespace std;
int x[100000], y[100000];
void gg() {
  puts("-1");
  exit(0);
}
int main() {
  int n;
  scanf("%d", &n);
  int pos = 0, neg = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    if (y[i] < 0)
      neg++;
    else if (y[i] > 0)
      pos++;
    else
      zero++;
  }
  if (pos && neg) gg();
  if (zero && n > 1) gg();
  if (neg)
    for (int i = 0; i < n; i++) y[i] = -y[i];
  double l = 0, r = 1e14;
  for (int i = 0; i < n; i++) l = max(l, y[i] / 2.0);
  for (int i = 0; i < 64; i++) {
    double m = (l + r) / 2, ll = -1e99, rr = 1e99;
    for (int j = 0; j < n; j++) {
      double t = 2.0 * m * y[j] - 1.0 * y[j] * y[j];
      ll = max(ll, x[j] - sqrt(t));
      rr = min(rr, x[j] + sqrt(t));
    }
    if (ll < rr)
      r = m;
    else
      l = m;
  }
  printf("%.10f\n", (l + r) / 2);
  return 0;
}
