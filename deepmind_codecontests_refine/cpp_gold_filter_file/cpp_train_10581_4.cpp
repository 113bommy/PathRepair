#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  double res = 1000000.0, ans;
  while (n--) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    ans = a / b;
    res = min(res, ans);
  }
  printf("%.10f\n", res * (double)m);
  return 0;
}
