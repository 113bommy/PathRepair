#include <bits/stdc++.h>
int main() {
  int i, j, n, sum = 0, cnt = 0;
  char a[101][101];
  scanf("%d ", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  for (i = 0; i < n; i++) {
    cnt = 0;
    for (j = 0; j < n; j++) {
      if (a[i][j] == 'c') cnt++;
    }
    sum += (cnt * (cnt - 1)) / 2;
  }
  cnt = 0;
  for (i = 0; i < n; i++) {
    cnt = 0;
    for (j = 0; j < n; j++) {
      if (a[j][i] == 'c') cnt++;
    }
    sum += (cnt * (cnt - 1)) / 2;
  }
  printf("%d\n", sum);
  return 0;
}
