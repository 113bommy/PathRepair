#include <bits/stdc++.h>
int main() {
  int n, found;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char s[101], p[101];
    scanf("%s %s", &s, &p);
    int k = strlen(s);
    found = 0;
    for (int x = 0; x < k; x++) {
      for (int y = 0; y < k; y++) {
        if (p[x] == s[y]) {
          found++;
          break;
        }
      }
    }
    if (found == k) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
