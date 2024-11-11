#include <bits/stdc++.h>
bool prm(int a) {
  int i;
  for (i = 2; i * i <= a && a % i; i++)
    ;
  return i * i > a;
}
int c[6666];
int main() {
  int n, a, i;
  scanf("%d", &n);
  a = n * (n + 1) / 2;
  if (a == 1) {
    printf("-1\n");
    return 0;
  }
  if (prm(a)) {
    for (i = 0; i < n; i++) printf(i == n - 1 ? "1\n" : "1 ");
    return 0;
  }
  if (a % 2 == 1 && prm(a - 2)) {
    printf("1 2");
    for (i = 3; i < n; i++) printf(" 1");
    puts("");
    return 0;
  }
  if (a % 2 == 0) {
    for (i = 3; !prm(i) || !prm(a - i); i += 2)
      ;
    a = i;
    for (i = 1; i <= n; i++) c[i] = 1;
    for (i = n; i; i--)
      if (a >= i) {
        a -= i;
        c[i] = 2;
      }
    for (i = 1; i <= n; i++) printf(i == n ? "%d\n" : "%d ", c[i]);
    return 0;
  }
  c[3] = 3;
  a -= 3;
  if (1) {
    for (i = 3; !prm(i) || !prm(a - i); i += 2)
      ;
    a = i;
    for (i = 1; i <= n; i++)
      if (i != 3) c[i] = 1;
    for (i = n; i; i--)
      if (i != 3 && a >= i) {
        a -= i;
        c[i] = 2;
      }
    for (i = 1; i <= n; i++) printf(i == n ? "%d\n" : "%d ", c[i]);
  }
  return 0;
}
