#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int t;
int n;
int a[55][55];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= int(n); i++)
      for (int j = 1; j <= int(n); j++) a[i][j] = 0;
    for (int i = 1; i <= int(n); i++)
      for (int j = 1; j <= int(n); j++) {
        char x;
        cin >> x;
        if (x == '0')
          a[i][j] = 1;
        else
          a[i][j] = 2;
      }
    bool ok = 1;
    for (int i = 1; i <= int(n); i++)
      for (int j = 1; j <= int(n); j++) {
        if (a[i][j] == 2 && a[i + 1][j] == 1 && a[i][j + 1] == 1) ok = 0;
      }
    if (ok)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
