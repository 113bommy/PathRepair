#include <bits/stdc++.h>
using namespace std;
void solve() {
  int d;
  cin >> d;
  double L = 0, R = d, mid;
  double big, small;
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
  while (true) {
    mid = L + (R - L) / 2;
    big = mid;
    small = d - mid;
    if (big * small > d)
      L = mid;
    else
      R = mid;
    if (fabs((big + small) - (big * small)) <= 0.000001 &&
        fabs((big + small) - d) <= 0.000001)
      break;
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
