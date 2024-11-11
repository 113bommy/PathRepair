#include <bits/stdc++.h>
using namespace std;
double s, a, b, c, sum;
double ans(double u) { return ((s * u) / sum); }
int main() {
  cin >> s;
  cin >> a >> b >> c;
  sum = a + b + c;
  if (sum == 0) {
    printf("1.0 1.0 1.0\n");
    return 0;
  }
  printf("%.10f %.10f %.10f\n", ans(a), ans(b), ans(c));
}
