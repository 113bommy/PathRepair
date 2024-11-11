#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, a[102][102], ans, n, m;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    sort(a[i], a[i] + m);
  }
  ans = INT_MIN;
  for (i = 0; i < n; i++) {
    if (a[i][0] > ans) ans = a[i][0];
  }
  cout << ans;
  return 0;
}
