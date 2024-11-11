#include <bits/stdc++.h>
int main() {
  char a[101];
  int l = 0, i;
  gets(a);
  while (a[l]) l++;
  i = l - 2;
  while (a[i] == ' ') i--;
  switch (a[i] & 0x1f) {
    case 1:
    case 5:
    case 9:
    case 15:
    case 21:
    case 25:
      printf("YES\n");
      break;
    default:
      printf("NO\n");
      break;
  }
  return 0;
}
