#include <bits/stdc++.h>
using namespace std;
long long a, b, c, x, y, z;
int main() {
  cin >> a >> b >> c >> x >> y >> z;
  a = a - x;
  if (a > 0) a = a / 2;
  b = b - y;
  if (b > 0) b = b / 2;
  c = c - z;
  if (c > 0) c = c / 2;
  if (a + b + c >= 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
