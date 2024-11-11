#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long int n, m;
  long long int cx, cy;
  long long int incx, incy;
  cin >> n >> m;
  cin >> cx >> cy;
  int k;
  cin >> k;
  long long int steps = 0;
  int left = 0;
  for (int i = 0; !left && i < k; i++) {
    cin >> incx >> incy;
    int stepsx, stepsy;
    int canx, cany;
    canx = cany = 1;
    if (incx > 0) {
      stepsx = floor((n - cx) / incx);
    } else if (incx < 0)
      stepsx = floor((cx - 1) / -incx);
    else
      canx = 0;
    if (incy > 0) {
      stepsy = floor((m - cy) / incy);
    } else if (incy < 0)
      stepsy = floor((cy - 1) / -incy);
    else
      cany = 0;
    long long int walk;
    if (canx && cany)
      walk = min(stepsx, stepsy);
    else if (canx)
      walk = stepsx;
    else
      walk = stepsy;
    steps += walk;
    if (cx + incx * walk < 1 || cx + incx * walk > n || cy + incy * walk < 1 ||
        cy + incy * walk > m) {
      left = 1;
      cout << steps << endl;
    } else {
      cx += incx * walk;
      cy += incy * walk;
    }
  }
  if (!left) cout << steps << endl;
  return 0;
}
