#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, m, i, j, mx, mn, flag, ans, temp;
  cin >> t;
  while (t--) {
    cin >> n;
    string a[n];
    flag = 1;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = n - 2; i >= 0; i--) {
      for (j = n - 2; j >= 0; j--) {
        if (a[i][j] == '1') {
          if (a[i][j + 1] == '1' || a[i + 1][j] == '1')
            continue;
          else {
            flag = 0;
            break;
          }
        }
      }
      if (flag == 0) break;
    }
    flag ? cout << "YES\n" : cout << "NO\n";
  }
}
