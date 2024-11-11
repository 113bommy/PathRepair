#include <bits/stdc++.h>
int main() {
  int c = 0, i, n, k, s[150];
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  for (i = 0; i < n; i++) {
    if (s[i] >= s[n - k] && s[i] > 0) c++;
  }
  printf("%d", c);
  return 0;
}
