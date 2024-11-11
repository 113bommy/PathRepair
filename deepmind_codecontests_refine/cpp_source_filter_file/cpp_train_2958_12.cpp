#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[101], b[101];
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + m);
  int flag1 = 0, flag2 = 0, res = 0;
  for (int k = a[n - 1]; k <= b[0]; ++k) {
    flag1 = 0, flag2 = 1;
    for (int i = 0; i < n; ++i) {
      if (a[i] <= k / 2) {
        flag1 = 1;
      }
    }
    for (int i = 0; i < m; ++i) {
      if (b[i] > k) {
        flag2 = flag2 * 1;
      } else {
        flag2 = 0;
      }
    }
    if (flag1 && flag2) {
      res = k;
      break;
    } else {
      res = -1;
    }
  }
  cout << res << "\n";
  return 0;
}
