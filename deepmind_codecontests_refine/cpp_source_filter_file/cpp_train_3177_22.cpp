#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, z, x, y, count = 0, sum = 0;
  cin >> a >> b >> c;
  cin >> x >> y >> z;
  if (a >= x)
    count += (a - x) / 2;
  else
    sum += x - a;
  if (b >= y)
    count += (b - y) / 2;
  else
    sum += y - b;
  if (c >= z)
    count += (c - z) / 2;
  else
    sum += z - c;
  if (count = sum)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
