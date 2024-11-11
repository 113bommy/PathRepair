#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, l;
  cin >> h >> l;
  double ans = (l * l - h * h) * 1.0 / (2 * h);
  printf("%.13f\n", ans);
  return 0;
}
