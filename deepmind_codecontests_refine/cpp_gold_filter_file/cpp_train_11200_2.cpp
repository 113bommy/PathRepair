#include <bits/stdc++.h>
int main() {
  char str[50];
  int n, i, ct = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    switch (str[0]) {
      case 'T':
        ct += 4;
        break;
      case 'C':
        ct += 6;
        break;
      case 'O':
        ct += 8;
        break;
      case 'D':
        ct += 12;
        break;
      case 'I':
        ct += 20;
    }
  }
  printf("%d\n", ct);
  return 0;
}
