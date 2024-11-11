#include <bits/stdc++.h>
using namespace std;
int n;
double r, v;
double l1, l2;
void init() { cin >> l1 >> l2; }
void process() {
  double len = l2 - l1;
  double low = max(len - r * 2, 0.), high = len + r * 2;
  for (int cnt = 0; cnt < 300; cnt++) {
    double mid = (low + high) / 2;
    if (2 * abs(sin(mid / (2.0 * r))) + mid >= len)
      high = mid;
    else
      low = mid;
  }
  printf("%.25f\n", low / v);
}
int main() {
  cin >> n >> r >> v;
  while (n--) {
    init();
    process();
  }
  return 0;
}
