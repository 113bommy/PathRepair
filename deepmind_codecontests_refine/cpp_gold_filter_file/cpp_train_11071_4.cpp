#include <bits/stdc++.h>
using namespace std;
double dist(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
int main() {
  int x1, y1, r1, R1, x2, y2, r2, R2;
  cin >> x1 >> y1 >> r1 >> R1 >> x2 >> y2 >> r2 >> R2;
  int k = 0;
  double d1 = dist(x1, y1, x2, y2);
  if (d1 >= R1 + R2 || d1 <= R1 - R2 || d1 <= r2 - R1) k += 1;
  if (d1 >= r1 + R2 || d1 <= r1 - R2 || d1 <= r2 - r1) k += 1;
  if (d1 >= R2 + R1 || d1 <= R2 - R1 || d1 <= r1 - R2) k += 1;
  if (d1 >= r2 + R1 || d1 <= r2 - R1 || d1 <= r1 - r2) k += 1;
  cout << k << endl;
  return 0;
}
