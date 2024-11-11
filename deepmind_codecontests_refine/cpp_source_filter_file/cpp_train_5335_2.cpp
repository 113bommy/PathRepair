#include <bits/stdc++.h>
using namespace std;
int a[1002], s1[1002], s2[1002], n;
int main() {
  int t;
  cin >> t;
  for (; t > 0; t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1)
      cout << 1 << " " << a[1] << " 0\n";
    else {
      for (int i = 1; i <= n; i++) s1[i] = a[i] + s1[i - 1];
      for (int i = n; i >= 1; i--) s2[i] = a[i] + s2[i + 1];
      int ta = 0, tb = 0, aa = 0, ab = 0, pa = 0, pb = n + 1;
      int i = 1, j = n, nr = 0;
      while (i < j) {
        aa = 0;
        if (i <= j) nr = nr + 1;
        while (aa <= ab and i <= j) {
          aa = aa + a[i];
          i = i + 1;
        }
        ta = ta + aa;
        pa = i - 1;
        ab = 0;
        if (j >= i) nr = nr + 1;
        while (ab <= aa and i <= j) {
          ab = ab + a[j];
          j = j - 1;
        }
        pb = j + 1;
        tb = tb + ab;
      }
      cout << nr << " " << ta << " " << tb << "\n";
    }
    for (int i = 0; i <= n + 1; i++) a[i] = s1[i] = s2[i] = 0;
  }
}
