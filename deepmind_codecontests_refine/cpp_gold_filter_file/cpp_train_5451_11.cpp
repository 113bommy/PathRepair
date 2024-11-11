#include <bits/stdc++.h>
using namespace std;
int main() {
  int xi, yi, zi, x, y, z;
  int c = 0;
  int a1, a2, a3, a4, a5, a6;
  cin >> x >> y >> z;
  cin >> xi >> yi >> zi;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  if (y < 0) c += a1;
  if (z > zi) c += a4;
  if (z < 0) c += a3;
  if (x > xi) c += a6;
  if (x < 0) c += a5;
  if (y > yi) c += a2;
  cout << c;
  return 0;
}
