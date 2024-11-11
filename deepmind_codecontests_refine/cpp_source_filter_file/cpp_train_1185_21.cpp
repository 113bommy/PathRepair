#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, d, ans;
  cin >> a >> b >> c >> d;
  ans = (a * (1 / (1 - ((a / b) * (c / d))))) / b;
  printf("%.10g", ans);
  return 0;
}
