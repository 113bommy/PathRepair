#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  int x, y;
  int a;
  cin >> a >> x >> y;
  if (y % a == 0 || abs(x) >= a)
    cout << -1;
  else if (y < a) {
    if (abs(x) < 1.0 * a / 2)
      cout << 1;
    else
      cout << -1;
  } else {
    y -= a;
    int k = y / a / 2;
    y %= (2 * a);
    int num = 1 + 3 * k;
    if (y > a) {
      if (x == 0)
        cout << -1;
      else
        cout << num + 2 + (x > 0 ? 1 : 0);
    } else {
      if (x < 1.0 * a / 2)
        cout << num + 1;
      else
        cout << -1;
    }
  }
}
