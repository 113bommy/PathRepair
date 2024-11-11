#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int p = -2;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == 0 && a[i + 1] == 1) {
        p = i;
      }
    }
    p++;
    if (p == -1) {
      if (a[0] == 1) {
        cout << n + 1 << ' ';
        for (int i = 0; i < n; i++) {
          cout << i + 1 << ' ';
        }
        cout << endl;
      } else {
        for (int i = 0; i < n; i++) {
          cout << i + 1 << ' ';
        }
        cout << n + 1 << ' ' << endl;
      }
    } else {
      for (int i = 0; i < p; i++) {
        cout << i + 1 << ' ';
      }
      cout << n + 1 << ' ';
      for (int i = p; i < n; i++) {
        cout << i + 1 << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
