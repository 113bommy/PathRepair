#include <bits/stdc++.h>
using namespace std;
int main() {
  double d, h, v, e, ans, term, term2, pi = atan(1) * 4;
  cin >> d >> h >> v >> e;
  term = pi * d * d * h / 4;
  term2 = -pi * d * d * e / 4 + v;
  if (term2 <= 0) {
    return cout << "NO" << endl, 0;
  }
  printf("%.8lf", term / term2);
}
