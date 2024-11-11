#include <bits/stdc++.h>
using namespace std;
char str[101][101];
int flag[101][101];
int main() {
  int n, k, i, j, r, c;
  scanf(" %d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf(" %s", str[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (str[i][j] == '.') {
        int cnt = k;
        for (r = i; r >= 0; r--) {
          if (cnt == 0) break;
          if (str[r][j] == '.') {
            cnt--;
          } else {
            break;
          }
        }
        if (cnt == 0) {
          for (r = i; r >= i - k + 1; r--) {
            flag[r][j]++;
          }
        }
        cnt = k;
        for (r = i; r < n; r++) {
          if (cnt == 0) break;
          if (str[r][j] == '.') {
            cnt--;
          } else {
            break;
          }
        }
        if (cnt == 0) {
          for (r = i; r <= i + k - 1; r++) {
            flag[r][j]++;
          }
        }
        cnt = k;
        for (c = j; c >= 0; c--) {
          if (cnt == 0) break;
          if (str[i][c] == '.') {
            cnt--;
          } else {
            break;
          }
        }
        if (cnt == 0) {
          for (c = j; c >= j - k + 1; c--) {
            flag[i][c]++;
          }
        }
        cnt = k;
        for (c = j; c < n; c++) {
          if (cnt == 0) break;
          if (str[i][c] == '.') {
            cnt--;
          } else {
            break;
          }
        }
        if (cnt == 0) {
          for (c = j; c <= j + k - 1; c++) {
            flag[i][c]++;
          }
        }
      }
    }
  }
  int maxi = 0;
  int row, col;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (maxi < flag[i][j]) {
        maxi = flag[i][j];
        row = i;
        col = j;
      }
    }
  }
  printf("%d %d\n", row + 1, col + 1);
  return 0;
}
