#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[105];
  cin >> n;
  int i, p;
  int sum = 0;
  for (i = 1; i <= n; i++) cin >> a[i];
  if ((n - 1) % 2 != 0 || n < 3)
    cout << "-1" << endl;
  else {
    for (i = n; i >= 3; i--) {
      if (a[i] <= 0) continue;
      p = i / 2;
      sum += a[i];
      a[p] -= a[i];
      a[2 * p] -= a[i];
      a[2 * p + 1] -= a[i];
    }
    if (a[1] > 0 || a[2] > 0) {
      sum += a[1] > a[2] ? a[1] : a[2];
    }
    cout << sum << endl;
  }
  return 0;
}
