#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  char map[n][100];
  for (int i = 0; i < n; ++i) {
    scanf("%s", map[i]);
  }
  printf("NO\n");
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (strcmp(map[i], map[j]) == 0) {
        printf("YES\n");
        break;
      }
      if (j == i - 1) {
        printf("NO\n");
      }
    }
  }
}
