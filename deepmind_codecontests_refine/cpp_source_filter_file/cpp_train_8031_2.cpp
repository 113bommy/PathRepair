#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, m, n;
  char a[200];
  int b[200][2];
  memset(b, -1, sizeof(b));
  scanf("%d%d\n", &n, &m);
  l = 0;
  for (i = 1; i <= n; i++) {
    scanf("%s", a);
    for (j = 1; j <= m; j++) {
      if (a[j - 1] == 'W') {
        if (b[i][0] == -1) b[i][0] = j;
        b[i][1] = j;
        l = i;
      }
    }
  }
  for (i = 1; i <= n; i++) {
  }
  k = 0;
  j = 1;
  for (i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      if (b[i][1] == -1) b[i][1] = j;
      k += b[i][1] - j;
      j = b[i][1];
      if (i < n && b[i + 1][1] == -1) b[i + 1][1] = j;
      if (i < n && b[i + 1][1] > b[i][1]) {
        k += b[i + 1][1] - j;
        j = b[i + 1][1];
      }
    } else {
      if (b[i][0] == -1) b[i][0] = j;
      k += j - b[i][0];
      j = b[i][0];
      if (i < n && b[i + 1][0] == -1) b[i][0] = j;
      if (i < n && b[i + 1][0] < b[i][0]) {
        k += j - b[i + 1][0];
        j = b[i + 1][0];
      }
    }
  }
  if (l == 0) l = 1;
  printf("%d\n", k + l - 1);
  return 0;
}
