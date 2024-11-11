#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n, x, y;
  cin >> n;
  x = 1;
  y = 1;
  string st, ans = "", ans1 = "";
  while (1) {
    if (n - x + n - y == n - 1) {
      break;
    }
    cout << "? " << x + 1 << " " << y << " " << n << " " << n << endl;
    cin >> st;
    if (st == "YES") {
      ans += "D";
      x++;
    } else {
      ans += "R";
      y++;
    }
  }
  x = n;
  y = n;
  while (1) {
    if (x + y == n + 1) {
      break;
    }
    cout << "? " << 0 << " " << 0 << " " << x << " " << y - 1 << endl;
    cin >> st;
    if (st == "YES") {
      ans1 += "R";
      y--;
    } else {
      x--;
      ans1 += "D";
    }
  }
  reverse(ans1.begin(), ans1.end());
  ans += ans1;
  cout << "! " << ans << endl;
  return 0;
}
