#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int main() {
  int y1, y2, yw, xb, yb, r;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  int yf = 2 * yw - y1 - 3 * r;
  double k = ((double)yf - (double)yb) / (0.0 - (double)xb), ans;
  if ((double)y2 - (double)y1 - (double)r > (sqrt(k * k + 1) * r)) {
    ans = ((double)(yw - r) - (double)yf) / k;
  } else {
    ans = -1;
  }
  printf("%.9lf", ans);
}
