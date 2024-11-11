#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  char array[101][101];
  int i, j;
  int count;
  int sum = 0;
  for (i = 0; i < n; i++) {
    scanf("%s", array[i]);
  }
  for (i = 0; i < n; i++) {
    count = 0;
    for (j = 0; j < n; j++) {
      if (array[i][j] == 'C') {
        count++;
      }
    }
    sum += count * (count - 1) / 2;
  }
  for (j = 0; j < n; j++) {
    count = 0;
    for (i = 0; i < n; i++) {
      if (array[i][j] == 'C') {
        count++;
      }
    }
    sum += count * (count - 1) / 2;
  }
  printf("%d\n", sum);
  return 0;
}
