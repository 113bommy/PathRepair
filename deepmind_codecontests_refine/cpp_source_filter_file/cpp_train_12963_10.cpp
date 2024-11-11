#include <bits/stdc++.h>
int imin(int a, int b) { return a < b ? a : b; }
int main() {
  int n, male[367], famale[367], a, b;
  char sex;
  int i, j, ans;
  while (scanf("%d", &n) != EOF) {
    getchar();
    for (i = 0; i < 367; i++) {
      male[i] = famale[i] = 0;
    }
    for (i = 0; i < n; i++) {
      scanf(" %c %d %d", &sex, &a, &b);
      for (j = a; j <= b; j++) {
        if (sex == 'M') {
          male[j]++;
        } else {
          famale[j]++;
        }
      }
    }
    ans = 0;
    for (i = 2; i < 367; i++) {
      if (imin(male[i], famale[i]) > ans) {
        ans = imin(male[i], famale[i]);
      }
    }
    printf("%d\n", ans * 2);
  }
  return 0;
}
