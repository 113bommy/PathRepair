#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x, y, z;
  cin >> x >> y >> z;
  if (x + z < y && y + z > x)
    cout << "-" << endl;
  else if (y + z < x && x + z > y)
    cout << "+" << endl;
  else if (x + z == y && y + z == x)
    cout << 0 << endl;
  else
    cout << "?" << endl;
  return;
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
