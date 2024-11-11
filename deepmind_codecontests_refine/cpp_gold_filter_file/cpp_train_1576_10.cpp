#include <bits/stdc++.h>
using namespace std;
int main() {
  double pi = 3.14159265359;
  double n, r;
  cin >> n >> r;
  double a = (pi / n);
  double ans = ((r * sin(a) / (1 - sin(a))));
  printf("%lf", ans);
  return 0;
}
