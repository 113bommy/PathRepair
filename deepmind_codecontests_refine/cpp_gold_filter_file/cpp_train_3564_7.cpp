#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, p = 0, po = 0, ne = 0, ans = 1;
    cin >> n;
    long long int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
      if (p == 0) {
        if (a[i] == b[i] && a[i] != 0) {
          p++;
          if (a[i] == 1)
            po++;
          else
            ne++;
          continue;
        } else if (a[i] == b[i] && a[i] == 0)
          continue;
        else {
          ans = 0;
          break;
        }
      } else {
        if (a[i] == b[i])
          ;
        else if (a[i] > b[i]) {
          if (ne == 0) {
            ans = 0;
            break;
          }
        } else {
          if (po == 0) {
            ans = 0;
            break;
          }
        }
        if (a[i] == 1) po++;
        if (a[i] == -1) ne++;
        if (po != 0 && ne != 0) {
          ans = 1;
          break;
        }
      }
    }
    if (ans == 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
