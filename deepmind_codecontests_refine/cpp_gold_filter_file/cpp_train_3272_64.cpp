#include <bits/stdc++.h>
int main() {
  long s[100], n, i, j, a;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &s[i]);
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (s[i] > s[j]) {
        a = s[i];
        s[i] = s[j];
        s[j] = a;
      }
    }
  }
  for (i = 0; i < n; i++) {
    printf(" %d", s[i]);
  }
  return 0;
}
