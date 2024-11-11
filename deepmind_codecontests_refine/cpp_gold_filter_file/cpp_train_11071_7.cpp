#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, r1, R1 = 0;
  int x2, y2, r2, R2 = 0;
  cin >> x1 >> y1 >> r1 >> R1;
  cin >> x2 >> y2 >> r2 >> R2;
  double d = sqrt((double)(((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))));
  int c = 0;
  if (r1 + R2 <= d || r2 - r1 >= d || r1 - R2 >= d) c++;
  if (R1 + R2 <= d || r2 - R1 >= d || R1 - R2 >= d) c++;
  if (r2 + R1 <= d || r1 - r2 >= d || r2 - R1 >= d) c++;
  if (R2 + R1 <= d || r1 - R2 >= d || R2 - R1 >= d) c++;
  cout << c << endl;
  return 0;
}
