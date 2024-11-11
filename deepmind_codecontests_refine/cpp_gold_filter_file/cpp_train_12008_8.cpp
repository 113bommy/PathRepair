#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x1, y1, x2, y2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  int x = abs(x1 - x2), y = abs(y1 - y2);
  if (x <= 4 && y <= 4 && x + y <= 6)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
