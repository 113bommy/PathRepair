#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, flag;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 2)
    cout << a[0] + 2 * (a[1] - a[0]);
  else {
    for (int i = 0; i < n - 2; i++) {
      if ((a[i + 2] - a[i + 1]) != (a[1 + i] - a[i])) {
        flag = 0;
        break;
      } else
        flag = 1;
    }
    if (flag) {
      cout << a[0] + (n) * (a[1] - a[0]);
    } else
      cout << a[n - 1];
  }
}
