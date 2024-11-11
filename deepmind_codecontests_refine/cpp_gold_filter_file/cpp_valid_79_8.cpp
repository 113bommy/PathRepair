#include <bits/stdc++.h>
using namespace std;
int n, a[55];
char s[100];
int p[100];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int fg = 0;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      a[i] = s[i] - '0';
      if (a[i] != 2 && a[i] != 3 && a[i] != 5 && a[i] != 7) {
        fg = 1;
        printf("1\n%d\n", a[i]);
        break;
      }
    }
    if (fg == 1) {
      continue;
    }
    puts("2");
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        int x = a[i] * 10 + a[j];
        if (x != 23 && x != 37 && x != 53 && x != 73) {
          fg = x;
          break;
        }
      }
      if (fg) break;
    }
    printf("%d\n", fg);
  }
  return 0;
}
