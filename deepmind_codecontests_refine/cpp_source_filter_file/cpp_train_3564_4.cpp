#include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000], c[1000];
int main() {
  int t;
  cin >> t;
  for (int h = 1; h <= t; ++h) {
    int n, f1 = 0, f2 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        if (b[i] < a[i]) {
          if (f1 == 0) {
            c[h] = 1;
            break;
          }
        } else {
          if (f2 == 0) {
            c[h] = 1;
            break;
          }
        }
      }
      if (a[i] == -1)
        f1++;
      else if (a[i] == 1)
        f2++;
    }
  }
  for (int i = 1; i <= t; ++i) {
    if (c[i] == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
