#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, k, i, j, t, x;
  int c[200];
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    c[i] = i;
  }
  cin >> m;
  int b[m];
  for (j = 0; j < m; j++) {
    cin >> b[j];
    c[i + j] = b[j];
  }
  x = m + n;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      t = 0;
      for (k = 0; k < x; k++) {
        if (a[i] + b[j] == c[k]) {
          t == 1;
          break;
        }
      }
      if (t == 0) {
        cout << a[i] << " " << b[j] << endl;
        goto here;
      }
    }
  }
here:
  return 0;
}
