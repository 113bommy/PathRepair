#include <bits/stdc++.h>
int main() {
  int arr[1005] = {0};
  int string[1005][5] = {0};
  int n, count = 0;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &string[i][1], &string[i][2]);
    arr[string[i][1]]++;
    arr[string[i][2]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 1) count++;
  }
  printf("%d\n", count);
}
