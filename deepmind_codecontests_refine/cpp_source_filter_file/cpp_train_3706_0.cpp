#include <bits/stdc++.h>
int check(int);
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (check(m)) {
    int i = n + 1;
    while (i < m) {
      if (check(i)) {
        printf("-1");
        return 0;
      }
      i++;
    }
    printf("YES");
  } else
    printf("-1");
  return 0;
}
int check(int x) {
  int i = 2;
  while (i * i <= x) {
    if (x % i == 0) return 0;
    i++;
  }
  return 1;
}
