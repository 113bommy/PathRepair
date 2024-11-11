#include <bits/stdc++.h>
int main() {
  int i, n, count = 0;
  scanf("%d", &n);
  char s[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  for (i = 0; i < n; i++) {
    if (s[i] != s[i + 1]) count++;
  }
  printf("%d", count);
  return 0;
}
