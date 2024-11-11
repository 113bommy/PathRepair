#include <bits/stdc++.h>
using namespace std;
void solve() {
  int d;
  cin >> d;
  double L = 0, R = d, mid;
  double big = 0, small = 0;
  if (d == 4) {
    printf("Y %.9lf %.9lf\n", 2.000000000, 2.000000000);
    return;
  } else if (d == 0) {
    printf("Y %.9lf %.9lf\n", 0.000000000, 0.000000000);
    return;
  } else if (d < 4) {
    printf("N\n");
    return;
  }
  while (fabs(d - (big * small)) > 1e-6) {
    mid = L + (R - L) / 2;
    big = mid;
    small = d - mid;
    if (big * small > d)
      L = mid;
    else
      R = mid;
  }
  printf("Y %.9lf %.9lf\n", big, small);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  };
}
