#include <bits/stdc++.h>
using namespace std;
int main() {
  int re = -1;
  int n, i, k, x, y;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    if (y == 0) {
      if (x <= y) re = max(0, re);
    } else {
      if (x < y) re = max(100 - y, re);
    }
  }
  cout << re << endl;
  return 0;
}
