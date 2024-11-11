#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x, y, z;
  long long s = 0;
  cin >> a >> b >> x >> y >> z;
  a = a - 2 * x - y;
  b = b - 3 * z - y;
  if (a < 0) s += abs(a);
  if (b < 0) s += abs(b);
  cout << s << endl;
  return 0;
}
