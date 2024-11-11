#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  double a, b, c, s, x, y, z, sum;
  cin >> s >> a >> b >> c;
  sum = a + b + c;
  if (sum == 0) {
    x = y = 0;
    z = s;
  } else {
    x = a / sum * s;
    y = b / sum * s;
    z = c / sum * s;
  }
  printf("%.12lf %.12lf %.12lf", x, y, z);
  return 0;
}
