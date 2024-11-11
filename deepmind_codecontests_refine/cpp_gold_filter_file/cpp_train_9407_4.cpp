#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:65777216")
using namespace std;
const long double EPS = 1e-11;
const int INF = 2000000000;
const long long lINF = 9223372036854775807;
const long double PI = 3.14159265358979323846;
int main() {
  long long y1, y2, yw, xb, yb, r, A, B, C;
  long double ans, yp, S, a, R;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  if (y2 - y1 < 2 * r) {
    cout << -1;
    return 0;
  }
  yw -= r;
  y1 += 2 * (yw - y1);
  y2 += 2 * (yw - y2);
  swap(y1, y2);
  y2 -= r;
  S = (y2 - y1) * xb;
  a = sqrt((long double)((xb * xb) + (y2 - yb) * (y2 - yb)));
  R = (long double)S / a;
  if ((long double)r - R > EPS) {
    cout << -1;
    return 0;
  }
  A = y2 - yb;
  B = xb;
  C = -B * y2;
  ans = (long double)(-(C + B * yw)) / (long double)A;
  printf("%.10lf", ans);
  return 0;
}
