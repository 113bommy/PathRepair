#include <bits/stdc++.h>
const int MaxN = 100500;
char a[MaxN], b[100];
int n, m;
int gp(int st) {
  int i, j, p;
  for (i = st; i < n - m; i++) {
    p = 0;
    for (j = 0; j < m; j++) {
      if (a[i + j] == b[j]) {
        p++;
      } else {
        break;
      }
    }
    if (p == m) {
      return i;
    }
  }
  return -1;
}
int main() {
  int i, r = 0, q;
  scanf("%s%s", a, b);
  n = strlen(a);
  m = strlen(b);
  for (i = 0; i < n - m; i++) {
    q = gp(i);
    if (q != -1) {
      i = q + m - 1;
      r++;
    } else {
      break;
    }
  }
  printf("%d\n", r);
  return 0;
}
