#include <bits/stdc++.h>
int main() {
  char a[50], b[50];
  scanf("%s", a);
  int k, j, l;
  if (strlen(a) % 2 == 0) {
    j = (strlen(a) / 2) - 1;
    l = j + 1;
  } else {
    j = (strlen(a) / 2);
    l = j + 1;
  }
  for (k = 0; k < strlen(a); k++) {
    if (k % 2 == 0) {
      b[k] = a[j];
      j--;
    } else {
      b[k] = a[l];
      l++;
    }
  }
  b[k] = '\0';
  printf("%s", b);
  return 0;
}
