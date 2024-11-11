#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, x0, y0, x1, y1;
  cin >> a >> b >> x0 >> y0 >> x1 >> y1;
  long long ac = (long long)floor((double)(y0 - x0) / (2 * b) + 1e-11);
  ac -= (long long)floor((double)(y1 - x1) / (2 * b) + 1e-11);
  ac = abs(ac);
  long long ab = (long long)floor((double)(y0 + x0) / (2 * a) + 1e-11);
  ab -= (long long)floor((double)(y1 + x1) / (2 * a) + 1e-11);
  ab = abs(ab);
  cout << max(ab, ac);
  return 0;
}
