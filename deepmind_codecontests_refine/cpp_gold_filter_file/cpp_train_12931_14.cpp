#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  char s[n][11], t[m][11];
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", t[i]);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int y;
    scanf("%d", &y);
    if (y % n == 0) {
      printf("%s", s[n - 1]);
    } else {
      printf("%s", s[y % n - 1]);
    }
    if (y % m == 0) {
      printf("%s", t[m - 1]);
    } else {
      printf("%s", t[y % m - 1]);
    }
    if (i != q - 1) {
      printf("\n");
    }
  }
  return 0;
}
