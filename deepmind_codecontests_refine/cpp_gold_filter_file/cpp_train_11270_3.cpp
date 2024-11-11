#include <bits/stdc++.h>
using namespace std;
int ar[200005];
int main() {
  long long t, n, i, ans;
  cin >> t;
  while (t--) {
    bool f = true;
    long long x = 0, y = 0, z = 0, mi, mx, mi_pos, mx_pos;
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    for (i = 2; i <= n; i++) {
      mi = 1e9, mx = 1e9, mi_pos = 0, mx_pos = 0;
      for (int j = i - 1; j >= 1; j--) {
        if (mi > ar[j]) {
          mi = ar[j];
          mi_pos = j;
        }
      }
      for (int k = i + 1; k <= n; k++) {
        if (mx > ar[k]) {
          mx = ar[k];
          mx_pos = k;
        }
      }
      if (ar[i] > mi and ar[i] > mx) {
        x = mi_pos;
        y = i;
        z = mx_pos;
        f = true;
        break;
      }
    }
    if (x != 0 and y != 0 and z != 0) {
      cout << "YES" << endl;
      cout << x << " " << y << " " << z << endl;
    } else
      cout << "NO" << endl;
  }
}
