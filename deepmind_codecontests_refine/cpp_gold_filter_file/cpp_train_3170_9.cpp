#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string y, f, x;
  int t1 = 0, t2 = 0;
  for (int ii = 0; ii < n; ii++) {
    if (ii == 0) {
      cin >> y;
      f = y;
      t1++;
      continue;
    }
    cin >> y;
    if (y == f)
      t1++;
    else {
      t2++;
      x = y;
    }
  }
  if (t1 > t2) {
    cout << f;
  } else {
    cout << x;
  }
  return 0;
}
