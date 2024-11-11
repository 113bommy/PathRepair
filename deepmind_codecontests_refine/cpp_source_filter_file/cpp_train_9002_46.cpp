#include <bits/stdc++.h>
int main() {
  int cell[101][101], i, j;
  int n;
  int r1, c1, r2, c2;
  unsigned long long int sum = 0;
  char specifier[6];
  specifier[0] = '%';
  specifier[1] = 'l';
  specifier[2] = 'l';
  specifier[3] = 'u';
  specifier[4] = '\n';
  specifier[5] = '\0';
  scanf("%d", &n);
  for (i = 0; i < 101; i++) {
    for (j = 0; j < 101; j++) {
      cell[i][j] = 0;
    }
  }
  while (n--) {
    scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
    for (i = r1; i <= r2; i++) {
      for (j = c1; j <= c2; j++) {
        cell[i][j]++;
      }
    }
  }
  for (i = 0; i < 101; i++) {
    for (j = 0; j < 100; j++) {
      sum += cell[i][j];
    }
  }
  printf(specifier, sum);
  return 0;
}
