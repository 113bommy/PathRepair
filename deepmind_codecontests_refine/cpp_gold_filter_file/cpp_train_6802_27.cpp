#include <bits/stdc++.h>
using namespace std;
int main() {
  double S, a, b, c;
  while (cin >> S >> a >> b >> c) {
    double t = a + b + c;
    if (t == 0)
      printf("%lf 0 0\n", S);
    else
      printf("%.10lf %.10lf %.10lf\n", S * a / t, S * b / t, S * c / t);
  }
  return 0;
}
