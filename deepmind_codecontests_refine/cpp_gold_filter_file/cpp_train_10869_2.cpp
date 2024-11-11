#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0, sum = 0, a[155], mn = 1005, x, y;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  mn = abs(a[1] - a[n]);
  x = 1;
  y = n;
  for (int i = 1; i <= n; i++) {
    if (abs(a[i] - a[i + 1]) < mn) {
      mn = abs(a[i] - a[i + 1]);
      x = i;
      y = i + 1;
    }
  }
  cout << x << ' ' << y;
  return 0;
}
