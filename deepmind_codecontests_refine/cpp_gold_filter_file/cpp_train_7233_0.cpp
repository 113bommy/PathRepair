#include <bits/stdc++.h>
int main() {
  int i, j;
  int n, m, q;
  int arr[505][505];
  scanf("%d%d%d", &n, &m, &q);
  for (i = 1; i <= n; i++) {
    arr[i][0] = 0;
    int cnt = 0;
    for (j = 1; j <= m; j++) {
      scanf("%d", &arr[i][j]);
      if (arr[i][j])
        cnt += 1;
      else
        cnt = 0;
      arr[i][0] = arr[i][0] > cnt ? arr[i][0] : cnt;
    }
  }
  arr[0][0] = arr[1][0];
  for (i = 1; i <= n; i++)
    arr[0][0] = arr[0][0] > arr[i][0] ? arr[0][0] : arr[i][0];
  while (q--) {
    scanf("%d%d", &i, &j);
    if (arr[i][j] == 0) {
      int cnt = 1;
      int k;
      arr[i][j] = 1;
      for (k = j - 1; k >= 1; k--)
        if (arr[i][k])
          cnt++;
        else
          break;
      for (k = j + 1; k <= m; k++)
        if (arr[i][k])
          cnt++;
        else
          break;
      arr[i][0] = arr[i][0] > cnt ? arr[i][0] : cnt;
      arr[0][0] = arr[i][0] > arr[0][0] ? arr[i][0] : arr[0][0];
    } else {
      arr[i][j] = 0;
      arr[i][0] = 0;
      int cnt = 0;
      for (j = 1; j <= m; j++) {
        if (arr[i][j])
          cnt += 1;
        else
          cnt = 0;
        arr[i][0] = arr[i][0] > cnt ? arr[i][0] : cnt;
      }
      arr[0][0] = arr[i][0];
      for (i = 1; i <= n; i++)
        arr[0][0] = arr[i][0] > arr[0][0] ? arr[i][0] : arr[0][0];
    }
    printf("%d\n", arr[0][0]);
  }
  return 0;
}
