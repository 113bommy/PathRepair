#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  double x, y, s = 0;
  for (int i = 0; i < a; i++) {
    cin >> x >> y;
    s += y;
  }
  s /= a;
  printf("%.3lf\n", s + 5);
  return 0;
}
