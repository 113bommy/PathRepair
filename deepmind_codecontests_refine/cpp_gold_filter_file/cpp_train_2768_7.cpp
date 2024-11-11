#include <bits/stdc++.h>
using namespace std;
double an = 2e9 + 100, x[100005], y[100005], tmp1, a, b, c, d;
int n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &x[i], &y[i]);
  x[n + 1] = x[1], x[n + 2] = x[2], y[n + 1] = y[1], y[n + 2] = y[2];
  for (int i = 1; i <= n; i++) {
    a = y[i + 2] - y[i];
    b = x[i + 2] - x[i];
    c = (b * y[i]) - (a * x[i]);
    d = (a * x[i + 1]) - (b * y[i + 1]) + c;
    d = fabs(d) / sqrt((a * a) + (b * b));
    an = min(an, d / 2);
  }
  an -= 1e-10;
  printf("%.12lf", an);
  return 0;
}
