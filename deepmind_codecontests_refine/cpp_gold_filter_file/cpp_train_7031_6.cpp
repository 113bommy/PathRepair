#include <bits/stdc++.h>
using namespace std;
int main() {
  int p1, p2, p3, p4, a, b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  int x = min(p1, p2);
  int y = min(p3, p4);
  int z = min(x, y);
  if (min(a, b) >= z) {
    cout << 0;
  } else if (z > max(a, b)) {
    cout << (b - a) + 1;
  } else {
    cout << z - min(a, b);
  }
  return 0;
}
