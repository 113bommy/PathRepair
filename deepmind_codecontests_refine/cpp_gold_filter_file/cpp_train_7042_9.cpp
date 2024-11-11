#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  int x1, x2, y1, y2;
  x1 = a % (m);
  y1 = a / (m);
  if (x1 == 0) x1 = m, --y1;
  x2 = b % (m);
  y2 = b / (m);
  if (x2 == 0) x2 = m, --y2;
  if (y1 == y2 || (x1 == 1 && x2 == m) || (x1 == 1 && b == n))
    cout << 1;
  else if (x1 == 1 || x2 == m || y2 - y1 == 1 || x1 - x2 == 1 || b == n)
    cout << 2;
  else
    cout << 3;
  return 0;
}
