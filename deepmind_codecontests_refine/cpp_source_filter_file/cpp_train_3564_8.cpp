#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n], b[n], one = 0, neg = 0, flag = 1;
    for (i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (i = 0; i < n; ++i) {
      cin >> b[i];
    }
    for (i = 0; i < n; ++i) {
      if (a[i] < b[i] && one == 0) {
        flag = 0;
        break;
      } else if (a[i] > b[i] && neg == 0) {
        flag = 1;
        break;
      }
      if (a[i] > 0)
        one = 1;
      else if (a[i] < 0)
        neg = 1;
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
