#include <bits/stdc++.h>
int n, m, k = 0;
char arr[2000][2001];
int check(int i, int j) {
  int v = 0;
  if (arr[i][j] != '.') return 0;
  if (i + 1 < n && arr[i + 1][j] == '.') v++;
  if (i - 1 >= 0 && arr[i - 1][j] == '.') v++;
  if (j + 1 < m && arr[i][j + 1] == '.') v++;
  if (j - 1 >= 0 && arr[i][j - 1] == '.') v++;
  return v;
}
void calc(int i, int j) {
  k -= 2;
  if (i + 1 < n && arr[i + 1][j] == '.') {
    arr[i][j] = '^';
    arr[i + 1][j] = 'v';
    if (check(i + 2, j) == 1) calc(i + 2, j);
    if (check(i + 1, j - 1) == 1) calc(i + 1, j - 1);
    if (check(i + 1, j + 1) == 1) calc(i + 1, j + 1);
  } else if (i - 1 >= 0 && arr[i - 1][j] == '.') {
    arr[i - 1][j] = '^';
    arr[i][j] = 'v';
    if (check(i - 2, j) == 1) calc(i - 2, j);
    if (check(i - 1, j - 1) == 1) calc(i - 1, j - 1);
    if (check(i - 1, j + 1) == 1) calc(i - 1, j + 1);
  } else if (j + 1 < m && arr[i][j + 1] == '.') {
    arr[i][j] = '<';
    arr[i][j + 1] = '>';
    if (check(i, j + 2) == 1) calc(i, j + 2);
    if (check(i - 1, j + 1) == 1) calc(i - 1, j + 1);
    if (check(i + 1, j + 1) == 1) calc(i + 1, j + 1);
  } else if (j - 1 >= 0 && arr[i][j - 1] == '.') {
    arr[i][j - 1] = '<';
    arr[i][j] = '>';
    if (check(i, j - 2) == 1) calc(i, j - 2);
    if (check(i - 1, j - 1) == 1) calc(i - 1, j - 1);
    if (check(i + 1, j - 1) == 1) calc(i + 1, j - 1);
  }
}
int main() {
  int i, j, flag = 0, f = 0;
  scanf("%d", &n);
  scanf("%d", &m);
  for (i = 0; i < n; i++) scanf("%s", arr[i]);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (arr[i][j] == '.') k++;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (check(i, j) == 1) calc(i, j);
    }
  }
  if (k > 0) {
    printf("Not unique");
    return 0;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) printf("%c", arr[i][j]);
    printf("\n");
  }
  return 0;
}
