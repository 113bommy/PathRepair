#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, b, c, n, x1, x2, y1, y2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> x2 >> y1 >> y2;
    b = (abs(x1 - y1) + 1);
    c = (abs(x2 - y2) + 1);
    a += b * c;
  }
  cout << a;
  return 0;
}
