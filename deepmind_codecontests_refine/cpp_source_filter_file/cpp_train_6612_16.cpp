#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, x2, y1, y2, mx;
  cin >> x1 >> y1 >> x2 >> y2;
  mx = x2 - x1;
  cout << max(mx, (y2 - y1));
  return 0;
}
