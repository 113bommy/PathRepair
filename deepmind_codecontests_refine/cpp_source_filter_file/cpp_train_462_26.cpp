#include <bits/stdc++.h>
using namespace std;
int main() {
  long long r, x, y, a, b, j = 0, h;
  double d;
  cin >> r >> x >> y >> a >> b;
  d = (double)sqrt(((x - a) * (x - a)) + ((y - b) * (y - b)));
  j = d / (r * 2);
  h = (long)d;
  if (h % r != 0 || d > h) j++;
  cout << j << endl;
  return 0;
}
