#include <bits/stdc++.h>
using namespace std;
int t1[3], t2[3];
int main() {
  int s1(0), s2(0), a, b, c, x, y, z;
  cin >> a >> b >> c >> x >> y >> z;
  if (a > x)
    s1 += (a - x) / 2;
  else
    s2 += (x - a);
  if (b > y)
    s1 += (b - y) / 2;
  else
    s2 += (y - b);
  if (c > z)
    s1 += (c - z) / 2;
  else
    s2 += (z - c);
  if (s1 + s2 >= 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
