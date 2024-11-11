#include <bits/stdc++.h>
using namespace std;
double a, b, c, n, sum;
double x, y, z;
int main() {
  cin >> n;
  cin >> a >> b >> c;
  sum = a + b + c;
  if (a == 0 && b == 0 && c == 0) cout << "0.000000 0.000000 0.000000", exit(0);
  x = (a / sum) * n;
  y = (b / sum) * n;
  z = (c / sum) * n;
  printf("%.6lf %.6lf %.6lf", x, y, z);
  return 0;
}
