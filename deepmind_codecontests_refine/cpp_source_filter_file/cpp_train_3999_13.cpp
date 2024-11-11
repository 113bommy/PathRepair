#include <bits/stdc++.h>
int main() {
  int i, j, k = 0;
  scanf("%d", &i);
  int arr[i];
  for (j = 0; j < i; j++) scanf("%d", &arr[j]);
  for (j = 0; j < i; j++) {
    if (arr[j] != arr[j + 1]) k++;
  }
  printf("%d", k + 1);
  return 0;
}
