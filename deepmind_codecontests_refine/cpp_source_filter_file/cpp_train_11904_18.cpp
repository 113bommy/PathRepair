#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
const int mod = 1e9 + 7;
int main() {
  int s, a, b, c;
  cin >> s >> a >> b >> c;
  if (a == 0 && b == 0 && c == 0)
    printf("0.0 0.0 0.0\n");
  else {
    double ans = 1.0 * s / (a + b + c);
    printf("%.12f %.12f %.1lf\n", a * ans, b * ans, c * ans);
  }
  return 0;
}
