#include <bits/stdc++.h>
int main() {
  int n, k, swap, temp, i, total = 0, l;
  scanf("%d%d", &n, &k);
  int arr[n];
  for (i = 0; i < n; i++) scanf("%d", &arr[i]);
  while (1) {
    swap = 0;
    for (i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swap = 1;
      }
    }
    if (swap == 0) break;
  }
  l = n % k;
  if (l > 0) total += 2 * (arr[l - 1] - 1);
  for (i = 1; i < n / k + 1; i++) total += 2 * (arr[k * i + l - 1] - 1);
  printf("%d", total);
  return 0;
}
