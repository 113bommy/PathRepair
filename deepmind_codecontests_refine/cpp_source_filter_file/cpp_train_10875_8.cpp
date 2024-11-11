#include <bits/stdc++.h>
using namespace std;
int n, m, n1, m1, a[60][60], ans = 1 << 30, res;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  cin >> n1 >> m1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i + n1 <= n && j + m1 <= m) {
        res = 0;
        for (int i1 = i; i1 < i + n1; i1++)
          for (int j1 = j; j1 < j + m1; j1++) res += a[i1][j1];
        ans = min(ans, res);
      }
      if (i + m1 <= m && j + n1 <= m) {
        res = 0;
        for (int i1 = i; i1 < i + m1; i1++)
          for (int j1 = j; j1 < j + n1; j1++) res += a[i1][j1];
        ans = min(ans, res);
      }
    }
  cout << ans;
  return 0;
}
