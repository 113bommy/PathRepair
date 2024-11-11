#include <bits/stdc++.h>
int main() {
  int arr[6] = {0}, x, i, j, sayac = 999999;
  for (i = 0; i < 5; i++) {
    scanf("%d", &x);
    if (i == 0 || i == 1)
      arr[i] = x;
    else if (i == 2)
      arr[i] = x / 2;
    else if (i == 4)
      arr[i] = x / 7;
    else
      arr[i] = x / 4;
  }
  for (i = 0; i < 5; i++)
    if (arr[i] < sayac) sayac = arr[i];
  printf("%d", sayac);
  return 0;
}
