#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, *arr, *a2d, j = 0;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    a2d = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    for (int i = n - 1; i > 0; i--)
      if (arr[i] != arr[i - 1] + 1) a2d[j++] = arr[i];
    if (arr[0] + 1 != arr[1]) a2d[j++] = arr[0];
    int flag = 0;
    for (int i = 1; i < j; i++)
      if (a2d[i] < a2d[i - 1]) {
        flag = 1;
        break;
      }
    if (flag)
      printf("No\n");
    else
      printf("Yes\n");
    free(arr);
    free(a2d);
  }
  return 0;
}
