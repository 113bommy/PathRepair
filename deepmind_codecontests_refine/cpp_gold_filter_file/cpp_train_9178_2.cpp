#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h, l;
  cin >> h >> l;
  double ans = ((l * l - h * h) * 1.0) / (2 * h * 1.0);
  printf("%.10lf\n", ans);
  return 0;
}
