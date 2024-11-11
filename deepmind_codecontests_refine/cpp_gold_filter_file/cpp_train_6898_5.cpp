#include <bits/stdc++.h>
int main() {
  int n, s = 0, i, j, k, b[1000], m = 0, temp, l = 0;
  char a[1000];
  scanf("%d", &n);
  getchar();
  while (n--) {
    gets(a);
    k = strlen(a);
    b[0] = 0;
    for (i = 0; i < k; i++) {
      if (a[i] == '1')
        s++;
      else {
        if (s != 0) {
          b[l] = s;
          l++;
        }
        s = 0;
      }
    }
    if (a[k - 1] == '1') {
      b[l] = s;
      l++;
    }
    for (i = 0; i < l - 1; i++) {
      for (j = i + 1; j < l; j++) {
        if (b[i] < b[j]) {
          temp = b[i];
          b[i] = b[j];
          b[j] = temp;
        }
      }
    }
    for (i = 0; i < l; i += 2) {
      m = m + b[i];
    }
    printf("%d\n", m);
    m = 0;
    s = 0;
    l = 0;
  }
  return 0;
}
