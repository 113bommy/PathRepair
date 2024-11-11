#include <bits/stdc++.h>
using namespace std;
int n, i, j, mx, x, y, a[1000005], b[1000005], m;
int main() {
  cin >> n;
  m = 0;
  for (i = 1; i <= n; ++i) {
    cin >> x;
    m = max(m, x);
    a[x]++;
    b[x] = i;
  }
  mx = -1;
  x = 0;
  y = 0;
  for (i = 1; i <= m; ++i) {
    if (a[i] > mx || (a[i] == mx && b[i] < x)) {
      x = b[i];
      mx = a[i];
      y = i;
    }
  }
  cout << y;
}
