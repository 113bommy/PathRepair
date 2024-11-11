#include <bits/stdc++.h>
using namespace std;
int main() {
  double d, h;
  cin >> h >> d;
  double result = (double)(d * d - h * h) / (2 * h);
  printf("%lf", result);
  return 0;
}
