#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, i, m = 0, sum = 0, sum1 = 0, y = 0, flag = 0;
    cin >> n >> x;
    int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sum1 = sum;
    if (sum % x != 0) {
      cout << n << "\n";
      continue;
    }
    for (i = 0; i <= n - 1; i++) {
      sum = sum - a[i];
      if (a[i] % x != 0) {
        m = n - i;
        flag = 1;
        break;
      }
    }
    for (i = n - 1; i >= 0; i--) {
      sum1 = sum1 - a[i];
      if (sum1 % x != 0) {
        y = i + 1;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "-1\n";
    } else {
      cout << max(y, m) << "\n";
    }
  }
}
