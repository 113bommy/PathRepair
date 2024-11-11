#include <bits/stdc++.h>
char a[200005], b[200005];
int cmp(char *p, char *q, int n) {
  if (!strncmp(p, q, n)) return 1;
  if (n % 2) return 0;
  int temp = n / 2;
  if (cmp(p, q, temp) && cmp(p + temp, q + temp, temp))
    return 1;
  else if (cmp(p + temp, q, temp) && cmp(p, q + temp, temp))
    return 1;
  return 0;
}
int main() {
  while (~scanf("%s%s", a, b)) {
    if (cmp(a, b, strlen(a)))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
