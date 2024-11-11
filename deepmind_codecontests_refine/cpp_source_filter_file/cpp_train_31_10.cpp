#include <bits/stdc++.h>
using namespace std;
int x, y, e, f, i, k, j, l, n, m, t;
int main() {
  cin >> n >> x >> y;
  if (n * y % 100 > 0)
    f = n * y / 100 + 1;
  else
    f = n * y / 100;
  if (x > f)
    cout << 0;
  else
    cout << x - f;
}
