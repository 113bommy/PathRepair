#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
int main() {
  int x, y;
  cin >> x >> y;
  if (x == 0 && y == 0) {
    cout << 0;
    exit(0);
  }
  if (y <= 0 && x > y && x <= -y + 1) {
    cout << abs(y) * 4;
  } else if (x >= 1 && y > x - 1 && y <= x) {
    cout << abs(x - 1) * 4 + 1;
  } else if (y > 0 && x >= -y && x < y) {
    cout << abs(y - 1) * 4 + 2;
  } else {
    cout << abs(x + 1) * 4 + 3;
  }
  return 0;
}
