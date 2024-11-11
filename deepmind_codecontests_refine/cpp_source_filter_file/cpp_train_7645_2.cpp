#include <bits/stdc++.h>
using namespace std;
double qmi(double a, int k) {
  double res = 1;
  while (k) {
    if (k & 1) res = res * a;
    a = a * a;
    k >>= 1;
  }
  return res;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  double ans = 0;
  for (double k = 1; k <= n; k++) {
    ans += k * (qmi(k / n, m) - qmi((k - 1) / m, n));
  }
  printf("%.12lf", ans);
  return 0;
}
