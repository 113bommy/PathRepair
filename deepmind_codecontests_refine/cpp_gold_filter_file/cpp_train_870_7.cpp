#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  for (int k = 1; k <= m; k++) {
    cin >> x >> y;
    x--;
    if ((x - 1) < 0) {
      a[x + 1] += a[x] - y;
      a[x] = 0;
    }
    if (x + 1 > n - 1) {
      a[x - 1] += y - 1;
      a[x] = 0;
    }
    if ((x - 1) >= 0 && (x + 1) <= n - 1) {
      a[x - 1] += y - 1;
      a[x + 1] += a[x] - y;
      a[x] = 0;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    cout << a[i] << '\n';
  }
  cout << a[n - 1];
  return 0;
}
