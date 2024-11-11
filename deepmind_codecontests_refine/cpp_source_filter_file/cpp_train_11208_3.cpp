#include <bits/stdc++.h>
int main() {
  int n;
  char str[101];
  scanf("%d", &n);
  int a, b, z = 0;
  for (a = 0; a <= n; a++) scanf("%c", &str[a]);
  for (a = 1; a <= n; a++) {
    if (str[a] == 'x') {
      if (a + 1 < n) {
        if (str[a + 1] == 'x' || str[a + 1] == '0') {
          if (a + 2 < n) {
            for (b = a + 2; b <= n; b++) {
              if (str[b] == 'x') {
                str[b] = '0';
                z++;
              } else if (str[b] != 'x' || str[b] != '0')
                break;
            }
          }
        }
      }
    }
  }
  printf("%d\n", z);
  return 0;
}
