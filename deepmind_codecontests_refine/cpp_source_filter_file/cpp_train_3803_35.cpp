#include <bits/stdc++.h>
using namespace std;
int a[11000][4];
int ans[110][110];
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) ans[i][j] = 0;
  for (int i = 0; i < q; i++) {
    int x1;
    cin >> x1;
    if (x1 != 3) {
      int x2;
      cin >> x2;
      x2--;
      a[i][0] = x1;
      a[i][1] = x2;
      a[i][2] = 0;
      a[i][3] = 0;
    } else {
      int x2, x3, x4;
      cin >> x2 >> x3 >> x4;
      x2--;
      x3--;
      a[i][0] = x1;
      a[i][1] = x2;
      a[i][2] = x3;
      a[i][3] = x4;
    }
  }
  for (int i = q - 1; i >= 0; i--) {
    if (a[i][0] == 3) {
      ans[a[i][1]][a[i][2]] = a[i][3];
    }
    if (a[i][0] == 1) {
      int x = ans[a[i][1]][n - 1];
      for (int j = n - 1; j > 0; j--) {
        ans[a[i][1]][j] = ans[a[i][1]][j - 1];
      }
      ans[a[i][1]][0] = x;
    }
    if (a[i][0] == 2) {
      int x = ans[m - 1][a[i][1]];
      for (int j = m - 1; j > 0; j--) {
        ans[j][a[i][1]] = ans[j - 1][a[i][1]];
      }
      ans[0][a[i][1]] = x;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << ans[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
