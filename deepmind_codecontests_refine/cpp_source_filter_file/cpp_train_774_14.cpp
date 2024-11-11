#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y, count = 0, i, j = 0, k;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  int b[m];
  for (i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  x = min(m, n);
  y = max(m, n);
  if (x == m) {
    for (i = 0; i < x; i++) {
      while (j < y) {
        if (abs(b[i] - a[j]) <= 1) {
          count++;
          j++;
          k = j;
          break;
        }
        j++;
      }
      if (j == y) j = k;
    }
  } else {
    for (i = 0; i < x; i++) {
      while (j < y) {
        if (abs(a[i] - b[j]) <= 1) {
          count++;
          j++;
          k = j;
          break;
        }
        j++;
      }
      if (j == y) j = k;
    }
  }
  cout << count;
  return (0);
}
