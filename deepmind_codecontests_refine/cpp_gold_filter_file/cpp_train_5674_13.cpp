#include <bits/stdc++.h>
int main() {
  long long int n, m, array[101][101], i, j, temp, array1[101] = {0}, pos = 0;
  scanf("%I64d %I64d", &n, &m);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%I64d", &array[i][j]);
    }
  }
  temp = 0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (array[i][j] > temp) {
        temp = array[i][j];
        pos = j;
      }
    }
    array1[pos]++;
    pos = 0;
    temp = 0;
  }
  temp = 0;
  pos = 0;
  for (j = 0; j < n; j++) {
    if (array1[j] > temp) {
      temp = array1[j];
      pos = j;
    }
  }
  printf("%I64d", pos + 1);
  return 0;
}
