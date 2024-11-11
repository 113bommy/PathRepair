#include <bits/stdc++.h>
using namespace std;
double a, b, n, x, y, s;
;
int main() {
  cin >> n >> x >> y;
  a = n * y / 100;
  if (a - x < 0)
    cout << 0;
  else if ((int)(a) == a)
    cout << a - x;
  else
    cout << (int)(a)-x + 1;
  return 0;
}
