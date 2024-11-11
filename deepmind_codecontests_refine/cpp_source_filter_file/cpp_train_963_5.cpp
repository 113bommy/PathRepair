#include <bits/stdc++.h>
using namespace std;
int main() {
  int d[10];
  int a[101];
  int h1[101];
  int h2[101];
  int i, j, k, t, n, f1, f2;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i <= 9; i++) d[i] = 0;
    for (i = 0; i <= 100; i++) h1[i] = 0;
    for (i = 0; i <= 100; i++) h2[i] = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      d[a[i]]++;
    }
    k = 0;
    j = 0;
    for (i = 0; i <= 9; i++) {
      if (d[i] == 0)
        continue;
      else if (d[i] == 1) {
        h1[i] = 1;
      } else {
        h1[i] = 1;
        h2[i] = 1;
      }
    }
    f1 = 0;
    f2 = 0;
    for (i = 0; i < 101; i++) {
      if (h1[i] == 0) {
        j = i;
        f1 = 1;
        break;
      }
    }
    if (f1 == 0) j = 0;
    for (i = 0; i < 101; i++) {
      if (h2[i] == 0) {
        k = i;
        f2 = 1;
        break;
      }
    }
    if (f2 == 0) k = 0;
    cout << k + j << endl;
  }
  return 0;
}
