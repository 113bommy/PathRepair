#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (a[0] == '1') {
      cout << n + 1 << ' ';
      for (int i = 1; i <= n; i++) cout << i << ' ';
      cout << endl;
    } else if (a[n - 1] == 0) {
      for (int i = 1; i <= n; i++) cout << i << ' ';
      cout << n + 1 << endl;
    } else {
      int f = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] == 0 && a[i + 1] == 1 && i < n - 1 && f == 0) {
          f = 1;
          cout << i + 1 << ' ' << n + 1 << ' ';
        } else
          cout << i + 1 << ' ';
      }
      cout << endl;
    }
  }
}
