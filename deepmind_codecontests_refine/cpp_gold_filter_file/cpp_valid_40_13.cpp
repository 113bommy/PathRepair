#include <bits/stdc++.h>
using namespace std;
void solve() {
  int m;
  cin >> m;
  int a[2][m], i, j;
  for (j = 0; j < 2; j++) {
    for (i = 0; i < m; i++) {
      cin >> a[j][i];
    }
  }
  for (i = 0; i < 2; i++) {
    for (j = 1; j < m; j++) {
      a[i][j] += a[i][j - 1];
    }
  }
  int ans = INT_MAX;
  for (i = 0; i < m; i++) {
    int sum;
    if (i == 0) {
      sum = a[0][m - 1] - a[0][0];
    }
    if (i == (m - 1)) {
      if ((m - 2) >= 0)
        sum = a[1][m - 2];
      else
        sum = 0;
    }
    if (i > 0 && i < (m - 1)) {
      int sum2;
      int sum3 = a[0][m - 1] - a[0][i];
      sum2 = a[1][i - 1];
      sum = max(sum2, sum3);
    }
    ans = min(ans, sum);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int i = 1; i <= tt; ++i) solve();
}
