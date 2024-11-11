#include <bits/stdc++.h>
using namespace std;
double n, a;
int main() {
  cin >> n >> a;
  double diff = 1e9 + 7;
  int ans = -1;
  double dx = 180.0 - (360.0 / n);
  dx = dx / (n - 2.0);
  for (int i = 3; i <= n; i++) {
    double angle = dx * (i - 2);
    if (abs(angle - a) < diff) {
      diff = abs(angle - a);
      ans = i;
    }
  }
  printf("2 1 %d\n", ans);
  return 0;
}
