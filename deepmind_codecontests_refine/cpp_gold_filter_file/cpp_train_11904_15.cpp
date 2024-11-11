#include <bits/stdc++.h>
using namespace std;
double s, a, b, c, d;
int main() {
  cin >> s >> a >> b >> c;
  d = a + b + c;
  if (!d) return printf("%lf 0 0\n", s), 0;
  printf("%.10lf %.10lf %.10lf\n", s * a / d, s * b / d, s * c / d);
  return 0;
}
