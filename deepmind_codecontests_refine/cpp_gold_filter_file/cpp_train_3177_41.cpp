#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x, y, z;
  cin >> a >> b >> c >> x >> y >> z;
  int bo = 0, ne = 0;
  if (a > x)
    bo += (a - x) / 2;
  else
    ne += x - a;
  if (b > y)
    bo += (b - y) / 2;
  else
    ne += y - b;
  if (c > z)
    bo += (c - z) / 2;
  else
    ne += z - c;
  if (ne > bo)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
