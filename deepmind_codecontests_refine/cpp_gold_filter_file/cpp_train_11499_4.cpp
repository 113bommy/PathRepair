#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, nt, l, re = 10;
int a[5][5] = {0}, v[5][5];
char c[5];
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", c);
    if (c[0] == 'R')
      j = 1;
    else if (c[0] == 'G')
      j = 2;
    else if (c[0] == 'B')
      j = 3;
    else if (c[0] == 'Y')
      j = 4;
    else
      j = 5;
    a[j - 1][c[1] - '1']++;
  }
  for (i = 0; i < 1024; i++) {
    int rt = 0, it = i, b[10] = {0}, st = 0;
    while (it) {
      rt = rt + (it & 1);
      b[st++] = it & 1;
      it = it >> 1;
    }
    if (rt >= re) continue;
    int sg = 1;
    for (j = 0; j < 25 && sg; j++) {
      if (!a[j / 5][j % 5]) continue;
      for (k = j + 1; k < 25 && sg; k++) {
        if (!a[k / 5][k % 5]) continue;
        if (k / 5 == j / 5 && b[j % 5 + 5] + b[k % 5 + 5] == 0)
          sg = 0;
        else if (j % 5 == k % 5 && b[j / 5] + b[k / 5] == 0)
          sg = 0;
        else if (j / 5 != k / 5 && k % 5 != j % 5 &&
                 b[j % 5 + 5] + b[k % 5 + 5] + b[j / 5] + b[k / 5] == 0)
          sg = 0;
      }
    }
    if (sg) {
      re = rt;
    }
  }
  printf("%d\n", re);
  return 0;
}
