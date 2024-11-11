#include <bits/stdc++.h>
char s[1000006];
int main() {
  long long int i, n, l, r, c, x;
  scanf("%s", s);
  n = strlen(s);
  for (i = 0; i < n; i++) {
    if (s[i] == '^') {
      x = i;
      break;
    }
  }
  c = 0;
  l = 0;
  for (i = x - 1; i >= 0; i--) {
    c++;
    if (s[i] >= '0' && s[i] <= '9') l = l + c * (s[i] - '0');
  }
  c = 0;
  r = 0;
  for (i = x + 1; i < n; i++) {
    c++;
    if (s[i] >= '0' && s[i] <= '9') r = r + c * (s[i] - '0');
  }
  if (l < r)
    printf("left");
  else if (r > l)
    printf("right");
  else
    printf("balance");
  return 0;
}
