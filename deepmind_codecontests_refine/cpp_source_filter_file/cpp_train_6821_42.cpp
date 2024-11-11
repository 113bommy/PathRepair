#include <bits/stdc++.h>
using namespace std;
int arr[100005][3];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int fin[n + 1][m + 1];
  bool row[n + 1];
  bool col[m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) fin[i][j] = 0;
  }
  for (int i = 1; i <= n; i++) row[i] = false;
  for (int i = 1; i <= m; i++) col[i] = false;
  for (int i = 1; i <= k; i++) {
    scanf("%d", &arr[i][0]);
    scanf("%d", &arr[i][1]);
    scanf("%d", &arr[i][2]);
  }
  for (int i = k; i >= 1; i--) {
    if (arr[i][0] == 1) {
      if (row[arr[i][1]] == false)
        row[arr[i][1]] = true;
      else
        arr[i][0] = -1;
    } else {
      if (col[arr[i][1]] == false)
        col[arr[i][1]] = true;
      else
        arr[i][0] = -1;
    }
  }
  for (int i = 1; i <= k; i++) {
    if (arr[i][0] == 1) {
      for (int j = 1; j <= m; j++) {
        fin[arr[i][1]][j] = arr[i][2];
      }
    } else {
      if (arr[i][0] == 2) {
        for (int j = 1; j <= n; j++) {
          fin[j][arr[i][1]] = arr[i][2];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", fin[i][j]);
    }
    printf("\n");
  }
  return 0;
}
