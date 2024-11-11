#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2, ans = 0;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2) x1++;
  if (y1 == y2) y1++;
  x2 = x2 > x1 ? x2 + 1 : x2 - 1;
  y2 = y2 > y1 ? y2 + 1 : y2 - 1;
  ans = abs(x1 - x2) + abs(y1 - y2);
  ans = ans * 2;
  cout << ans;
  return 0;
}
