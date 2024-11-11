#include <bits/stdc++.h>
using namespace std;
char a[101][101][101];
char flag[101][101][101];
int main() {
  int ans = 0;
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%s", a[i][j]);
      for (int l = 0; l < k; l++) {
        a[i][j][l] -= '0';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int l = 0; l < k; l++) {
        if (!a[i][j][l]) continue;
        if ((a[i + 1][j][l]) && (!flag[i + 1][j][l])) {
          if ((a[i + 2][j][l]) || ((a[i + 1][j + 1][l]) && (!a[i][j + 1][l])) ||
              ((a[i + 1][j][l + 1]) && (!a[i][j][l + 1]))) {
            flag[i + 1][j][l] = 1;
            ans++;
          }
        }
        if ((a[i][j + 1][l]) && (!flag[i][j + 1][l])) {
          if ((a[i][j + 2][l]) || ((a[i + 1][j + 1][l]) && (!a[i + 1][j][l])) ||
              ((a[i][j + 1][l + 1]) && (!a[i][j][l + 1]))) {
            flag[i][j + 1][l] = 1;
            ans++;
          }
        }
        if ((a[i][j][l + 1]) && (!flag[i][j][l + 1])) {
          if ((a[i][j][l + 2]) || ((a[i + 1][j][l + 1]) && (!a[i + 1][j][l])) ||
              ((a[i][j + 1][l + 1]) && (!a[i][j + 1][l]))) {
            flag[i][j][l + 1] = 1;
            ans++;
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
