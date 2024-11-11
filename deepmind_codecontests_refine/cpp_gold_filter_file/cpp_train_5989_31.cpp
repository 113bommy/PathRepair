#include <bits/stdc++.h>
int main() {
  int m, sum = 0;
  scanf("%d", &m);
  char arr[m][m];
  for (int i = 0; i < m; i++) {
    scanf("%s", arr[i]);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 'C') {
        for (int k = j + 1; k < m; k++) {
          if (arr[i][k] == 'C') {
            sum++;
            continue;
          }
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 'C') {
        for (int k = i + 1; k < m; k++) {
          if (arr[k][j] == 'C') {
            sum++;
            continue;
          }
        }
      }
    }
  }
  printf("%d", sum);
  return 0;
}
