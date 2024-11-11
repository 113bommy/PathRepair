#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int x, y;
  cin >> n >> k >> x >> y;
  long double sum = 0;
  for (int i = 1; i < n; i++) {
    int xx, yy;
    cin >> xx >> yy;
    sum += hypot(xx - x, yy - y);
    x = xx;
    y = yy;
  }
  printf("%.9Lf\n", (k * sum) / 50.0);
  return 0;
}
