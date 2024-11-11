#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, x2, y1, y2;
  cin >> x1 >> x1 >> x1 >> y1 >> x2 >> y2;
  x1 = abs(x1 - x2);
  x2 = abs(y1 - y2);
  if (x1 <= 5 && x2 <= 5 && x1 + x2 < 9)
    cout << "First\n";
  else
    cout << "Second\n";
  return 0;
}
