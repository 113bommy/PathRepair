#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m, i, j, ans = 0;
  cin >> n >> m;
  int a[n][2 * m + 2];
  for (i = 0; i < n; i++)
    for (j = 0; j < 2 * m; j++) cin >> a[i][j];
  for (i = 0; i < n; i++) {
    for (j = 0; j < 2 * m; j += 2)
      if (a[i][j] == 1 or a[i][j + 1] == 1) ans++;
  }
  cout << ans;
  return 0;
}
