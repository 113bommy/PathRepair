#include <bits/stdc++.h>
int main() {
  int a[4], x = 0, c;
  char s[100001];
  for (int i = 0; i < 4; i++) scanf("%d", &a[i]);
  scanf("%s", s);
  for (int i = 0; i < s[i]; i++) {
    c = s[i];
    x += a[c - 49];
  }
  printf("%d\n", x);
}
