#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, a, b, c;
  cin >> s >> a >> b >> c;
  double x = 0.0, y = 0.0, z = 0.0;
  if (a || b || c) {
    x = s * a / (double)(a + b + c);
    y = s * b / (double)(a + b + c);
    z = s * c / (double)(a + b + c);
  }
  printf("%.12f %.12f %.12f", x, y, z);
  return 0;
}
