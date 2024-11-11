#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  double x0, y0, x, y, ans, sum = 0;
  cin >> n >> k;
  cin >> x0, y0;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    sum += sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
    x0 = x;
    y0 = y;
  }
  cout << fixed << setprecision(6) << sum * k / 50;
  return 0;
}
