#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2, a, b;
  cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
  if (abs(x1 - x2) % a || abs(y1 - y2) % b ||
      ((abs(x1 - x2) / a - abs(y1 - y2) / b) % 2))
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
