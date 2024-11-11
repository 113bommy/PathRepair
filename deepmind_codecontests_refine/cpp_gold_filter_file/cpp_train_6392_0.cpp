#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m;
  long long R;
  cin >> m >> R;
  double sum = 0.0;
  for (long long v = 1; v <= m; ++v) {
    sum += 2 * R;
    if (v < m) {
      sum += R + sqrt(2.0) * R + R;
      sum += (m - v - 1) * (m - v - 1) * R;
      sum += (m - v - 1) * (R + 2 * sqrt(2.0) * R);
    }
    if (v > 1) {
      sum += R + sqrt(2.0) * R + R;
      sum += (v - 2) * (v - 2) * R;
      sum += (v - 2) * (R + 2 * sqrt(2.0) * R);
    }
  }
  printf("%.10f\n", sum / ((double)m * m));
  return 0;
}
