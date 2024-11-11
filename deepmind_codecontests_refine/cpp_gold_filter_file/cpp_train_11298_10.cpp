#include <bits/stdc++.h>
char name[101][12], cg[101][11];
int n, i, j, k;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %s", &name[i], &cg[i]);
  }
  for (i = 0; i < n; i++) {
    if (cg[i][0] == 'r') {
      printf("%s\n", name[i]);
    }
  }
  for (i = 0; i < n; i++) {
    if (cg[i][0] == 'w' || cg[i][1] == 'h') {
      printf("%s\n", name[i]);
    }
  }
  for (i = 0; i < n; i++) {
    if (cg[i][0] == 'm') {
      printf("%s\n", name[i]);
    }
  }
  for (i = 0; i < n; i++) {
    if (cg[i][0] == 'c' && cg[i][1] == 'a') {
      printf("%s\n", name[i]);
    }
  }
  return 0;
}
