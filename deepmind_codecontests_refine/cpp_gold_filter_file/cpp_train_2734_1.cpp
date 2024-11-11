#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int j = 0; j < n; j++) {
      int b;
      cin >> b;
      a[j] = b;
    }
    sort(a, a + n);
    if (n > 1) {
      for (int j = 1; j < n; j++) {
        if (a[j] - a[j - 1] <= 1) {
          if (j == n - 1) {
            cout << "YES" << endl;
          }
          continue;
        } else {
          cout << "NO" << endl;
          break;
        }
      }
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
