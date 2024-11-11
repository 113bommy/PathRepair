#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  ;
  double x1, y1, x2, y2, r1, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  double dist =
      sqrt((fabs(x2 - x1) * fabs(x2 - x1)) + (fabs(y2 - y1) * fabs(y2 - y1)));
  if (dist > r1 + r2)
    printf("%.100f", ((double)(dist - r1 - r2) / (double)2));
  else if (dist + r1 < r2)
    printf(".100f", ((double)(r2 - (r1 + dist)) / (double)2));
  else if (dist + r2 < r1)
    printf("%.100f", ((double)(r1 - (r2 + dist)) / (double)2));
  else
    cout << 0;
  return 0;
}
