#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  printf("%.10lf\n", a * d * 1.0 / (b * d - a * c));
  return 0;
}
