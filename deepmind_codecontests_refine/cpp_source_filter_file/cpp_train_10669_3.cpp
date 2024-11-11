#include <bits/stdc++.h>
int main() {
  int x, i, j, t, ind, cnt = 1;
  scanf("%d", &x);
  int *arr, *parr;
  arr = (int *)malloc(x * sizeof(int));
  parr = (int *)malloc(x * sizeof(int));
  for (i = 0; i < x; i++) {
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < x; i++) {
    parr[i] = 1;
  }
  for (i = 0; i < x; i++) {
    for (j = i + 1; j < x; j++) {
      if (arr[i] < arr[j]) {
        parr[i]++;
      }
    }
  }
  for (i = 0; i < x; i++) {
    printf("%d ", parr[i]);
  }
}
