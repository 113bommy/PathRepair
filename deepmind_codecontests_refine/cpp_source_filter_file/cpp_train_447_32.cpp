#include <bits/stdc++.h>
int Space[50][50];
int main() {
  int a, b, n, v = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &Space[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      a = 0;
      b = 0;
      for (int l = 0; l < n; l++) {
        a += Space[i][l];
        b += Space[l][j];
      }
      if (a > b) v++;
    }
  printf("%d", v);
  return 0;
}
