#include <bits/stdc++.h>
using namespace std;
int n;
double p;
double a[101010], b[101010];
bool ok(double x) {
  double s = 0;
  for (int i = (int)(0); i < (int)(n); i++) {
    double f = -a[i] * x + b[i];
    if (f < 0) s += f;
  }
  return -s <= p * x;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n >> p;
  for (int i = (int)(0); i < (int)(n); i++) cin >> a[i] >> b[i];
  double lb = 0, ub = 1e9;
  for (int hoge = (int)(0); hoge < (int)(400); hoge++) {
    double mid = (lb + ub) / 2.0;
    if (ok(mid))
      lb = mid;
    else
      ub = mid;
  }
  if (abs(lb - 1e9) < 1e-5)
    printf("-1\n");
  else
    printf("%.10f\n", lb);
  return 0;
}
