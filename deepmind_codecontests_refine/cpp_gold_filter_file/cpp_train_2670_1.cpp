#include <bits/stdc++.h>
int s[200006], c;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    while (c && s[c - 1] == x) c--, x++;
    s[c++] = x;
  }
  printf("%d\n", c);
  for (int i = 0; i < c; i++) printf("%d ", s[i]);
  puts("");
  return 0;
}
