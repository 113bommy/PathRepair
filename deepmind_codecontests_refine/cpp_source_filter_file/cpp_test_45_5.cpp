#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int n;
    int x = 1;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (a[0] == 1) {
      x++;
    }
    for (int i = 1; i < n; i++) {
      if (a[i] == 1) {
        if ((a[i] == 1) && (a[i - 1] == 1)) {
          x = x + 5;
        } else {
          x++;
        }
      }
      if ((a[i] == 0) && (a[i - 1] == 0)) {
        x = -1;
        break;
      }
    }
    cout << x;
  }
}
