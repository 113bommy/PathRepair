#include <bits/stdc++.h>
int main() {
  long long width = 1, height = 1;
  int n;
  char mov[5];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", mov);
    if (strcmp(mov, "UL") == 0 || strcmp(mov, "DL") == 0)
      width++;
    else if (strcmp(mov, "ULDR") == 0)
      width++, height++;
    else
      height++;
  }
  printf("%I64d\n", width * height);
}
