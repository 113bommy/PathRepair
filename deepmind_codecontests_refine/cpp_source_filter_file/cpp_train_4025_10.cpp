#include <bits/stdc++.h>
using namespace std;
int main() {
  int hh, mm, h, d, c, n;
  cin >> hh >> mm;
  cin >> h >> d >> c >> n;
  double a, b;
  a = (h + (n - 1)) / n * c;
  if (hh >= 20) {
    b = a * 0.8;
  } else {
    b = (h + (60 - mm) + (19 - hh) * 60 + (n - 1)) / n * c * 0.8;
  }
  printf("%8.4f\n", max(a, b));
  return 0;
}
