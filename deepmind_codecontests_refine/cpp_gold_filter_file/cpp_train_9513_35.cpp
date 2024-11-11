#include <bits/stdc++.h>
using namespace std;
int n, m, i, x[300], y[300];
int main() {
  cin >> n >> m;
  if (m == 3 && n >= 5) {
    cout << -1;
    return 0;
  }
  x[1] = 1;
  y[1] = 0;
  for (i = 1; i <= m; i++) {
    cout << x[i] << " " << y[i] << endl;
    x[i + 1] = x[i] + i - 1;
    y[i + 1] = y[i] + 1;
  }
  for (i = m + 1; i <= n; i++)
    cout << -99999 - x[i - m] << " " << y[i - m] << endl;
  return 0;
}
