#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, ans, f, k, t;
char a[101][101];
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) cin >> a[i][j];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      f = 0;
      for (k = 1; k <= n; k++)
        if ((int)a[i][j] - 48 < (int)a[k][j] - 48 && i != k) {
          f = 1;
          break;
        }
      if (f == 0) {
        ans++;
        break;
      }
    }
  cout << ans << endl;
  return EXIT_SUCCESS;
}
