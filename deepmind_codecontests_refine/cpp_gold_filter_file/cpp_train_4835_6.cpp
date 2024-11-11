#include <bits/stdc++.h>
using namespace std;
const int MAX = 109;
int a[MAX][MAX], n, m, k, ans = 1e9;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  if (k < m) {
    for (int i = 0; i < m; i++) {
      int cnt = 0;
      for (int j = 0; j < m; j++) {
        int l = 0;
        for (int k = 0; k < n; k++) l += a[k][i] != a[k][j];
        cnt += min(l, n - l);
      }
      ans = min(ans, cnt);
    }
  } else {
    for (int i = 0; i < (1 << m); i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        int l = 0;
        for (int k = 0; k < m; k++) l += a[j][k] == (i >> k & 1);
        cnt += min(l, m - l);
      }
      ans = min(ans, cnt);
    }
  }
  if (ans > k)
    cout << -1;
  else
    cout << ans;
  return 0;
}
