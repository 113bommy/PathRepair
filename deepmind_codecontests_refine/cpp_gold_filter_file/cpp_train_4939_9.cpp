#include <bits/stdc++.h>
using namespace std;
char f[101][101];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> f[i][j];
  int ans = INT_MAX;
  if (n <= k) {
    for (int i = 0; i < (1 << n); i++) {
      int v = 0;
      for (int j = 0; j < m; j++) {
        int t = 0;
        for (int k = 0; k < n; k++) {
          t += ((i >> k) & 1) == (f[k][j] - '0');
        }
        v += min(t, n - t);
      }
      ans = min(ans, v);
    }
  } else {
    for (int i = 0; i < m; i++) {
      int v = 0;
      for (int j = 0; j < m; j++) {
        int t = 0;
        for (int k = 0; k < n; k++) {
          t += f[k][j] == f[k][i];
        }
        v += min(t, n - t);
      }
      ans = min(ans, v);
    }
  }
  if (ans > k) ans = -1;
  cout << ans;
  return 0;
}
