#include <bits/stdc++.h>
using namespace std;
const static int inf = 10000000;
const static int mod = 1000000007;
bool check(int dx, int dy) {
  if (dx > dy) {
    swap(dx, dy);
  }
  if (dx >= 6 || dy >= 6) {
    return false;
  }
  if (dx <= 4 && dy <= 4) {
    return true;
  }
  if ((dx == 4 || dx == 5) && dy == 5) {
    return false;
  }
  return true;
}
int main() {
  int n, m, x, y, a, b;
  while (cin >> n >> m >> x >> y >> a >> b) {
    int dx = abs(x - a) + 1;
    int dy = abs(y - b) + 1;
    if (check(dx, dy)) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
  }
  return 0;
}
