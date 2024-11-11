#include <bits/stdc++.h>
int a[100005];
char c[100005];
int main() {
  int n, i, s = 0, s1 = 0, s2 = 0;
  for (scanf("%d", &n), i = 0; i < n; i++) scanf("%d", &a[i]);
  scanf("%s", c);
  for (i = 0; i < n; i++) {
    if (c[i] == '1') {
      s2 += a[i];
      s2 = s1 > s2 ? s1 : s2;
      s = s2 > s ? s2 : s;
    }
    s1 += a[i];
  }
  printf("%d\n", s);
  return 0;
}
