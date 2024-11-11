#include <bits/stdc++.h>
using namespace std;
void ret(string s) {
  cout << s;
  exit(0);
}
int main() {
  int x1, x2, y1, y2, n;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  if (x1 * x2 == 0 && x1 + x2 == n)
    cout << min(n + y1 + y2, 3 * n - y1 - y2);
  else if (y1 * y2 == 0 && y1 + y2 == n)
    cout << min(n + x1 + x2, 3 * n - x1 - x2);
  else
    cout << abs(x1 - x2) + abs(y1 - y2);
  return 0;
}
