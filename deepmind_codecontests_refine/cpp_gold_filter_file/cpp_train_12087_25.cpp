#include <bits/stdc++.h>
int main() {
  int n, i, num[110], hard = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
  }
  for (i = 1; i <= n; i++) {
    if (num[i] == 1) hard++;
  }
  if (hard == 0)
    printf("EASY\n");
  else
    printf("HARD\n");
  return 0;
}
