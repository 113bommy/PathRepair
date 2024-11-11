#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[101], y[101], i, j, n, p, q;
  cin >> n;
  memset(x, -1, sizeof(x));
  memset(y, -1, sizeof(y));
  for (i = 0; i < n; i++) {
    cin >> p >> q;
    x[p]++;
    y[q]++;
  }
  p = q = 0;
  for (i = 0; i < 100; i++) {
    if (x[i] >= 0) p++;
    if (y[i] >= 0) q++;
  }
  cout << min(p, q) << endl;
}
