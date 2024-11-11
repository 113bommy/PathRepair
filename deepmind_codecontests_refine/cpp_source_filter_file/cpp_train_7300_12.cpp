#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, m, h, p = -1, q;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 1; i < n; i++) {
    for (j = i; j <= n - 2; j++) {
      m = 1;
      h = a[i - 1];
      q = a[j];
      for (k = i + 1; k <= j; k++) {
        m = m + (h / a[k]);
        q = q + ((h / a[k]) * a[k]);
        h = h % a[k];
      }
      h = q;
      for (k = 0; k < n; k++) {
        m = m - (h / a[k]);
        h = h % a[k];
      }
      if ((m < 0) and (p == -1 or q < p)) {
        p = q;
      }
    }
  }
  cout << p;
}
