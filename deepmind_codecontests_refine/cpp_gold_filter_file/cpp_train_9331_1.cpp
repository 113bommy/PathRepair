#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long x, y, z;
  cin >> x >> y >> z;
  long long yl = (x * 2) + y;
  long long bl = (z * 3) + y;
  long long p = 0, q = 0;
  if (a < yl) p = yl - a;
  if (b < bl) q = bl - b;
  cout << p + q << endl;
  return 0;
}
