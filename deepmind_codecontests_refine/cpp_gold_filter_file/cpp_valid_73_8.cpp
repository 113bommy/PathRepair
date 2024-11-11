#include <bits/stdc++.h>
using namespace std;
int a[114514], b[114514];
int main() {
  int t, n, m, x, y;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int l1 = 1; l1 <= n; l1++) {
      cin >> a[l1];
    }
    x = 0;
    for (int l1 = 1; l1 <= n; l1++) {
      y = 1;
      for (int l2 = 1; l2 <= n; l2++) {
        if (a[l2] != l2) {
          y = 0;
          break;
        }
      }
      if (y) {
        break;
      }
      for (int l2 = l1 % 2; l2 < n; l2 += 2) {
        if (a[l2] > a[l2 + 1]) swap(a[l2], a[l2 + 1]);
      }
      x++;
    }
    cout << x << endl;
  }
}
