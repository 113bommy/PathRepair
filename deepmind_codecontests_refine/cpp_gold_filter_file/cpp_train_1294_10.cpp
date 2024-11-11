#include <bits/stdc++.h>
using namespace std;
int main() {
  double x, y, sum = 0, ans;
  int n, i;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x >> y;
    sum += y;
  }
  ans = sum * 1.0 / n * 1.0 + 5;
  printf("%.3lf", ans);
  return 0;
}
