#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, f, s = 0;
  int a[101][101];
  cin >> n;
  for (f = 0; f < n; f++) {
    for (i = 0; i < n; i++) {
      cin >> a[f][i];
    }
  }
  for (f = 0; f < n; f++) {
    s += a[n / 2][f];
  }
  for (f = 0; f < n; f++) {
    s += a[f][n / 2];
  }
  for (i = 0; i < n; i++) {
    s += a[i][i];
  }
  for (i = n - 1, f = 0; f <= n - 1 && i >= 0; i-- && f++) {
    s += a[i][f];
  }
  cout << s - 4 * a[n / 2][n / 2];
  return 0;
}
