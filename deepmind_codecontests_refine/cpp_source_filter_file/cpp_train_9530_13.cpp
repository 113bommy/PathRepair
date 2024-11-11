#include <bits/stdc++.h>
int main(void) {
  int n;
  scanf("%d", &n);
  int before, after;
  char username[11];
  int good = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s %d %d", username, &before, &after);
    if (before < 2400) {
      continue;
    }
    if (after < before) {
      continue;
    }
    good += 1;
  }
  if (good > 0) {
    printf("YES\n");
    return 0;
  }
  printf("NO\n");
}
