#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  long long x, y, z;
  cin >> a >> b >> c;
  cin >> x >> y >> z;
  long long a1 = a - x;
  long long b1 = b - y;
  long long c1 = c - z;
  long long extra_ball = 0;
  if (a1 > 0) extra_ball += a1 / 2 + a1 % 2;
  if (b1 > 0) extra_ball += b1 / 2 + b1 % 2;
  if (c1 > 0) extra_ball += c1 / 2 + c1 % 2;
  if (a1 > 0) a -= (a1 + a1 % 2);
  if (b1 > 0) b -= (b1 + b1 % 2);
  if (c1 > 0) c -= (c1 + c1 % 2);
  if (extra_ball >= (x - a) + (y - b) + (z - c))
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
