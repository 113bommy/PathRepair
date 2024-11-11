#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long x, y;
  cin >> x >> y;
  if (x > 0 && y < 0) {
    cout << "0 " << y - x << " " << x - y << " 0";
  } else if (x < 0 && y < 0) {
    cout << x + y << " 0 0 " << y + x;
  } else if (x > 0 && y > 0) {
    cout << "0 " << x + y << " " << x + y << " 0";
  } else {
    cout << x - y << " 0 0 " << y - x;
  }
  return 0;
}
