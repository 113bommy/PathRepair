#include <bits/stdc++.h>
int main() {
  int n, i, j, c;
  scanf("%d", &n);
  int arr[n - 1];
  for (i = 0; i < (n - 1); i++) scanf("%d", &arr[i]);
  int child[n];
  int count[n];
  for (i = 0; i < n; i++) {
    child[i] = 0;
    count[i] = 0;
  }
  for (i = 0; i < (n - 1); i++) child[arr[i] - 1] += 1;
  for (i = 0; i < (n - 1); i++)
    if (child[i + 1] == 0) count[arr[i] - 1] += 1;
  c = 0;
  for (i = 0; i < n; i++)
    if (count[i] < 3 && count[i] > 0) {
      c = 1;
      break;
    }
  if (c == 0)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
