#include <bits/stdc++.h>
int main() {
  int n, k, i;
  int j = 0;
  scanf("%d %d", &n, &k);
  int arr[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n; i++) {
    if (arr[i] >= arr[k] && arr[k] != 0) j++;
  }
  printf("%d", j);
  return 0;
}
