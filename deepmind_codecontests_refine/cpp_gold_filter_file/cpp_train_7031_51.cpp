#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f, p, q, x, y, cnt = 0;
  cin >> a >> b >> c >> d >> x >> y;
  e = min(a, min(b, min(c, d)));
  if (e < x)
    cout << 0;
  else if (y >= e)
    cout << e - x;
  else
    cout << y - x + 1;
}
