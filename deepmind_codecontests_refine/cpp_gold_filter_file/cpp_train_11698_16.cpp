#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, x, y;
  int at = 0, ar = 0, bt = 0, br = 0;
  cin >> n;
  while (n--) {
    cin >> t >> x >> y;
    if (t == 1) {
      ar += x;
      at += x + y;
    } else {
      br += x;
      bt += x + y;
    }
  }
  if (ar >= at / 2)
    cout << "LIVE" << endl;
  else
    cout << "DEAD" << endl;
  if (br >= bt / 2)
    cout << "LIVE" << endl;
  else
    cout << "DEAD" << endl;
  return 0;
}
