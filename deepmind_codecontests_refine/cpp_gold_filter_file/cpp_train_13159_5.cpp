#include <bits/stdc++.h>
using namespace std;
int main() {
  int c1, c2, c3, c4, x = 0, y = 0, z, i;
  cin >> c1 >> c2 >> c3 >> c4;
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (i = 0; i < n; i++) {
    x += min(a[i] * c1, c2);
  }
  x = min(x, c3);
  for (i = 0; i < m; i++) {
    y += min(b[i] * c1, c2);
  }
  y = min(y, c3);
  z = min(x + y, c4);
  cout << z;
}
