#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int m, x, y;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (x == 1) {
      a[x] += a[x - 1] - y;
      a[x - 1] = 0;
    } else if (y == n) {
      a[x - 2] += y - 1;
      a[x - 1] = 0;
    } else {
      a[x] += a[x - 1] - y;
      a[x - 2] += y - 1;
      a[x - 1] = 0;
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << endl;
}
