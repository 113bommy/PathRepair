#include <bits/stdc++.h>
int main() {
  int n, i, j, l;
  scanf("%d", &n);
  int number[100];
  int num[100];
  for (i = 0; i < n; ++i) {
    scanf("%d", &number[i]);
  }
  for (j = 0; j < n; ++j) {
    num[number[j] - 1] = j + 1;
  }
  for (l = 0; l < n; ++l) {
    printf("%d ", num[l]);
  }
}
