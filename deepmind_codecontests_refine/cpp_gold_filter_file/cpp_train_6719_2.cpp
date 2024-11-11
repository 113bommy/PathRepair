#include <bits/stdc++.h>
int main() {
  int n, a;
  int i = 0, j = 0;
  scanf("%d%d", &n, &a);
  int arr[n];
  for (i = 0; i < n; ++i) scanf("%d", &arr[i]);
  int count = 0;
  if (arr[a - 1] == 1) count += 1;
  i = 1;
  a = a - 1;
  while (a - i >= 0 && a + i < n) {
    if (arr[a + i] == 1 && arr[a - i] == 1) count += 2;
    i = i + 1;
  }
  if (a - i < 0)
    for (j = a + i; j < n; ++j)
      if (arr[j] == 1) count += 1;
  if (a + i == n)
    for (j = 0; j <= a - i; ++j)
      if (arr[j] == 1) count += 1;
  printf("%d", count);
  return 0;
}
