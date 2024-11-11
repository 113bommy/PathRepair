#include <bits/stdc++.h>
int main() {
  int n, i, j, flag, l, k;
  char arr[101];
  char temp;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%s", &arr);
    l = strlen(arr);
    if (l > 26)
      printf("No\n");
    else {
      flag = 0;
      for (k = 0; k < l - 1; k++) {
        for (j = 0; j < l - k - 1; j++) {
          if (arr[j] > arr[j + 1]) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
          }
        }
      }
      for (j = 0; j < l - 1; j++) {
        k = arr[j + 1] - arr[j];
        if (k != 1) {
          flag = 1;
          break;
        }
      }
      if (flag == 0)
        printf("Yes\n");
      else
        printf("No\n");
    }
  }
  return 0;
}
