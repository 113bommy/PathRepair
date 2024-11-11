#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, z, x, y, s1 = 0, s2 = 0;
  cin >> a >> b >> c >> x >> y >> z;
  if (a > x)
    s1 += (a - x) / 2;
  else
    s2 += x - a;
  if (b > y)
    s1 += (b - y) / 2;
  else
    s2 += y - b;
  if (c > z)
    s1 += (c - z) / 2;
  else {
    s2 += z - c;
  }
  if (s1 >= s2)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
