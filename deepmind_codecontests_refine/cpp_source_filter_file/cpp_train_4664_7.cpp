#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  x--, y--;
  int pos[] = {300000, 100000, 200000};
  int ans = 0;
  if (x <= 2) ans += pos[x];
  if (y <= 2) ans += pos[y];
  cout << ans + (x == 0 and y == 0) * 400000 << '\n';
}
