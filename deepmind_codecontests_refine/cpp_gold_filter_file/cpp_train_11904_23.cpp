#include <bits/stdc++.h>
const double eps = 1e-10;
const int INF = (1 << 30);
using namespace std;
int main() {
  double s, a, b, c, k;
  int aa, bb, cc, sum;
  while (cin >> s >> aa >> bb >> cc) {
    sum = aa + bb + cc;
    if (!sum) {
      a = s;
      b = 0;
      c = 0;
    } else {
      k = s / ((double)sum);
      a = aa;
      b = bb;
      c = cc;
      a *= k;
      b *= k;
      c *= k;
    }
    printf("%.10lf %.10lf %.10lf\n", a, b, c);
  }
  return 0;
}
