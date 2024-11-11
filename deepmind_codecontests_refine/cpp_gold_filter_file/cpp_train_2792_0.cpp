#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, d;
  cin >> n >> m >> d;

  double ans, y = m - 1;
  if (d == 0) {
    ans = y / n;
  } else {
    double x = n - d;
    ans = 2.0 * x / n / n * y;
  }
  printf("%.9f\n", ans);
}