#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int fastMin(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ y; }
int main() {
  long long m;
  double r;
  cin >> m >> r;
  double s2 = sqrt(2);
  double ans = (m * m + 3 * m - 1) / (3 * (double)m) * 2 * r;
  double r1 = 2 * (m - 1) * (2 - s2) * r;
  double r2 = (m * m - m - (m - 1) * 2) * (2 - s2) * r;
  ans -= (r1 + r2) / (m * (double)m);
  printf("%.15f\n", ans);
}
