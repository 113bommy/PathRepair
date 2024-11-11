#include <bits/stdc++.h>
int main(void) {
  int t, n;
  scanf("%d", &t);
  char a[50005], b[50005], c[50005];
  while (t--) {
    scanf("%d", &n);
    int count = 0, k = 0;
    scanf("%s", a);
    for (int i = 0; i <= n; i++) {
      if (a[i] == '1' && k == 0) {
        count = i;
        k = 1;
      }
      if (k == 1) {
        b[i] = '0';
        c[i] = a[i];
        if (i == count) {
          b[i] = '1';
          c[i] = '0';
        }
      } else if (k == 0) {
        if (a[i] == '0') b[i] = c[i] = '0';
        if (a[i] == '2') b[i] = c[i] = '1';
      }
      printf("%c", b[i]);
    }
    printf("\n");
    for (int j = 0; j <= n; j++) {
      printf("%c", c[j]);
    }
    printf("\n");
  }
  return 0;
}
