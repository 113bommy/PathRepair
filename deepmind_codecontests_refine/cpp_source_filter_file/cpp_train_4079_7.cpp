#include <bits/stdc++.h>
using namespace std;
int up, down, left1, right1;
int main() {
  int t;
  int n;
  cin >> t;
  while (t--) {
    cin >> n;
    up = 1e6;
    down = -(1e6);
    left1 = -(1e6);
    right1 = 1e6;
    while (n--) {
      int x, y;
      cin >> x >> y;
      int tmp;
      cin >> tmp;
      if (!tmp) left1 = max(left1, x);
      cin >> tmp;
      if (!tmp) up = min(up, y);
      cin >> tmp;
      if (!tmp) right1 = min(right1, x);
      cin >> tmp;
      if (!tmp) down = max(down, y);
    }
    if (up >= down && left1 <= right1) {
      cout << 1 << " " << left1 << " " << down << endl;
    } else {
      cout << "0" << endl;
    }
  }
  return 0;
}
