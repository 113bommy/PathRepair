#include <bits/stdc++.h>
char borze[201], dec[201];
int i, j;
int main() {
  scanf("%s", borze);
  i = 0;
  j = 0;
  while (borze[i] != '\0') {
    if (borze[i] == '.') {
      j++;
      dec[j] = '0';
      i++;
    } else if (borze[i + 1] == '.') {
      j++;
      dec[j] = '1';
      i = i + 2;
    } else {
      j++;
      dec[j] = '2';
      i = i + 2;
    }
  }
  for (i = 0; i <= j; i++) printf("%c", dec[i]);
  return 0;
}
