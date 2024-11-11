#include <bits/stdc++.h>
using namespace std;
int t, n, a[1010];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int flag = 1, sum = 0, pd, k = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0 && n == 1) flag = 0;
    }
    if (flag) {
      cout << -1 << '\n';
    } else {
      for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
          flag = 0;
          cout << 1 << '\n' << i << '\n';
          k = 1;
          break;
        } else if (a[i] % 2 != 0 && sum == 0) {
          sum++;
          pd = i;
        } else if (a[i] % 2 != 0 && sum == 1)
          sum++;
        if (sum == 2) {
          cout << 2 << '\n' << pd << ' ' << i << '\n';
          k = 1;
          break;
        }
      }
    }
  }
  return 0;
}
