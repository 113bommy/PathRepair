#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, x, y, z;
  cin >> a >> b >> c;
  cin >> x >> y >> z;
  long long need_a = 0, need_b = 0, need_c = 0, canmake_a = 0, canmake_b = 0,
            canmake_c = 0;
  if (x > a)
    need_a = x - a;
  else if (x < a)
    canmake_a = (a - x) / 2;
  if (y > b)
    need_b = y - b;
  else if (y < b)
    canmake_b = (b - y) / 2;
  if (z > c)
    need_c = z - c;
  else if (z < c)
    canmake_c = (c - z) / 2;
  if (canmake_a + canmake_b + canmake_c <= need_a + need_b + need_c)
    cout << "No";
  else
    cout << "Yes";
  return 0;
}
