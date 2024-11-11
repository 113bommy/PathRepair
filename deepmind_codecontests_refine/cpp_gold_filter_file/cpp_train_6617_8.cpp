#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  double n1, n2, x, y, sum1 = 0, sum2 = 0, t;
  cin >> n >> n1 >> n2;
  double a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, less<double>());
  x = (n1 > n2) ? n1 : n2;
  t = (n1 < n2) ? n1 : n2;
  for (i = n - 1; i >= n - (n1 + n2); i--) {
    if (i > n - t - 1)
      sum1 += a[i];
    else
      sum2 += a[i];
  }
  std::cout << std::setprecision(8) << std::fixed;
  y = sum1 / t + sum2 / x;
  cout << y;
  return 0;
}
