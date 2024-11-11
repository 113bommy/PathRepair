#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x1, y1, x2, y2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  int dx = abs(x1 - x2) - 1;
  int dy = abs(y1 - y2) - 1;
  if (dx > 3 || dy > 3) {
    cout << "Second" << endl;
  } else if (dx <= 2 && dy <= 2) {
    cout << "First" << endl;
  } else if (dx <= 1 || dy <= 1) {
    cout << "First" << endl;
  } else if (dx < 3 || dy < 3) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}
