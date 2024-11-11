#include <bits/stdc++.h>
int main() {
  int i, m, j;
  char a[100], b[100];
  scanf("%s %s", &a, &b);
  if (strlen(a) != strlen(b)) {
    printf("NO");
    return 0;
  }
  j = strlen(b) - 1;
  for (i = 0; i < strlen(a); i++) {
    if (a[i] != b[j]) {
      printf("NO");
      return 0;
    }
    j--;
  }
  printf("YES");
}
