#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long a, x, y;
  cin >> a;
  if (a % 2 == 0) {
    x = 4;
    y = a - x;
    cout << x << " " << y << endl;
  } else {
    x = 9;
    y = a - x;
    cout << x << " " << y << endl;
  }
  return 0;
}
