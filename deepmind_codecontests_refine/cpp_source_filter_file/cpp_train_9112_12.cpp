#include <bits/stdc++.h>
using namespace std;
using namespace std;
string read_string() {
  static char s[int(1e6 + 5)];
  scanf("%s", s);
  return string(s);
}
double a[200005];
int n, k;
bool ok(double mid) {
  double remainder = 0;
  for (int i = 1; i <= n; i++) {
    double x = mid - a[i];
    if (x < 1e-9) {
      remainder -= x - x * k / 100;
    }
    if (x > 1e-9) {
      remainder -= x;
    }
  }
  return remainder > -1e-9;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%Lf", &a[i]);
  double st = 0, en = 1000;
  while (fabs(st - en) > 1e-9) {
    double mid = (st + en) / 2;
    ok(mid) ? st = mid : en = mid;
  }
  printf("%.6f", st);
  return 0;
}
