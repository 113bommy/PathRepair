#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[3];
  while (cin >> n) {
    cin >> a[0] >> a[1] >> a[2];
    int dis = 0;
    if (n == 1)
      cout << 0 << endl;
    else if (n == 2) {
      cout << min(a[0], a[1]) << endl;
    } else {
      if (a[0] > a[1]) {
        dis += a[1];
        dis += min(a[2], a[0]) * (n - 2);
      } else {
        dis += a[0];
        dis += min(a[1], a[2]) * (n - 2);
      }
      cout << dis << endl;
    }
  }
  return 0;
}
