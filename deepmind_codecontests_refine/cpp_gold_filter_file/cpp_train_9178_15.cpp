#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h, l;
  double x;
  cin >> h >> l;
  x = (l * l - h * h) * 1.00000000000000 / (2 * h);
  printf("%.13lf", x);
}
