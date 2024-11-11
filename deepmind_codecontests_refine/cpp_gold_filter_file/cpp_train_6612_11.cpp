#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, dx, dy;
  cin >> x >> y;
  cin >> dx >> dy;
  cout << max(abs(dx - x), abs(dy - y));
  return 0;
}
