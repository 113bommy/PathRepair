#include <bits/stdc++.h>
int main() {
  long long int n;
  scanf("%lld", &n);
  long long int arr[n];
  long long int i, j, c = 0, x = 0, y = 0, z = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n; i++) {
    if (arr[i] == 25) {
      x++;
    } else if (arr[i] == 50) {
      y++;
      if (x >= 1) {
        x--;
      } else {
        c = 1;
        break;
      }
    } else if (arr[i] == 100) {
      z++;
      if (y >= 1 && x >= 1) {
        y = y - 1;
        x = x - 1;
      } else if (y < 1 && x >= 3) {
        x = x - 3;
      } else {
        c = 1;
        break;
      }
    }
  }
  if (c == 0) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return (0);
}
