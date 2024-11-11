#include <bits/stdc++.h>
using namespace std;
int n, a[200005], c[200005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n == 1)
    cout << "YES\n1\n";
  else if (n == 2)
    cout << "YES\n1 0\n";
  else {
    int mx = -1, mn = 1e7 + 9;
    for (int i = 1; i <= n; i++) {
      if (a[i] <= mx && a[i] >= mn) {
        cout << "NO\n";
        return 0;
      } else if (a[i] > mx && a[i] < mn) {
        if (a[i] > a[i + 1]) {
          c[i] = 1;
          mn = a[i];
        } else {
          c[i] = 0;
          mx = a[i];
        }
      } else if (a[i] <= mx) {
        c[i] = 1;
        mn = a[i];
      } else {
        c[i] = 0;
        mx = a[i];
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << c[i] << ' ';
  return 0;
}
