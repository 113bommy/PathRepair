#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, d, e;
  cin >> t;
  bool c1, c2;
  c1 = false;
  c2 = true;
  while (t--) {
    cin >> n;
    int a[n], b[n];
    d = e = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int s = 0; s < n; s++) {
      cin >> b[s];
    }
    if (b[0] == a[0]) {
      c1 = true;
    }
    for (int f = 0; f < n; f++) {
      if (a[f] == 1) {
        d = f;
        break;
      }
    }
    for (int g = 0; g < n; g++) {
      if (a[g] == -1) {
        e = g;
        break;
      }
    }
    for (int h = 1; h < n; h++) {
      if (((b[h] < a[h] & e >= h) || (b[h] > a[h] & d >= h)) & c1) {
        c2 = false;
        cout << "NO" << endl;
        break;
      }
    }
    if (c1 & c2) {
      cout << "YES" << endl;
    }
    if (!c1) cout << "NO" << endl;
    c1 = false;
    c2 = true;
  }
  return 0;
}
