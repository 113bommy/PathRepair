#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, h;
  cin >> h >> d;
  double result = (double)(d * d - h * h) / (2 * h);
  printf("%.13f", result);
  return 0;
}
