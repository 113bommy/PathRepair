#include <bits/stdc++.h>
using namespace std;
int main() {
  int testCases, t = 0;
  int x, y, z, x1, y1, z1, a1, a2, a3, a4, a5, a6;
  cin >> x >> y >> z;
  cin >> x1 >> y1 >> z1;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  int sum = 0;
  if (y < 0) sum += a1;
  if (y >= y1) sum += a2;
  if (z < 0) sum += a3;
  if (z >= z1) sum += a4;
  if (x < 0) sum += a5;
  if (x >= x1) sum += a6;
  cout << sum << endl;
  return 0;
}
