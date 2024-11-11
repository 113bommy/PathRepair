#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  int n, big, small;
  cin >> n;
  for (int ii = 1; ii <= n; ii++) cin >> a[ii];
  for (int ii = 1; ii <= n; ii++) {
    if (a[ii] == 1) small = ii;
    if (a[ii] == n) big = ii;
  }
  if (abs(small - big) == n - 1)
    cout << n - 1 << endl;
  else {
    if (small > big) {
      if (n - big > small - 1)
        cout << n - big << endl;
      else
        cout << small << endl;
    } else {
      if (n - small > big - 1)
        cout << n - small << endl;
      else
        cout << big << endl;
    }
  }
  return 0;
}
