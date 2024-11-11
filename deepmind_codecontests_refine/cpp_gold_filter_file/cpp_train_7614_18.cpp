#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int row[maxn], col[maxn];
int ans[maxn][maxn];
int main() {
  int k, c, h;
  cin >> k >> c >> h;
  for (int i = 1; i <= c; i++) cin >> col[i];
  for (int i = 1; i <= k; i++) cin >> row[i];
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= c; j++) {
      cin >> ans[i][j];
    }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= c; j++) {
      if (ans[i][j] == 1) ans[i][j] = row[i];
    }
  }
  for (int j = 1; j <= c; j++) {
    int flag = 1;
    for (int i = 1; i <= k; i++) {
      if (ans[i][j] > col[j]) ans[i][j] = col[j];
      if (col[j] > ans[i][j] && ans[i][j] != 0 && flag == 1) {
        if (row[i] >= col[j]) {
          flag = 0;
          ans[i][j] = col[j];
        }
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= c; j++) printf("%d ", ans[i][j]);
    printf("\n");
  }
}
