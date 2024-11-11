#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, d;
  d = 0;
  cin >> n >> m;
  int a[n];
  int b[m];
  int c[n][m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    d = d + b[i];
  }
  sort(a, a + n);
  sort(b, b + m);
  if (a[n - 1] > b[0]) {
    cout << "-1";
    return 0;
  } else {
    for (int i = 0; i < n; i++) {
      if (i < n - 2) {
        d = d + a[i] * m;
      }
      if (a[n - 1] != b[0]) {
        if (i == n - 2) {
          d = d + a[i] * (m - 1);
        }
        if (i == n - 1) {
          d = d + a[i];
        }
      } else {
        if (i == n - 2) {
          d = d + a[i] * m;
          break;
        }
      }
    }
  }
  cout << d;
}
