#include <bits/stdc++.h>
int main() {
  int nseg, ulim;
  scanf("%d%d", &nseg, &ulim);
  int arr[nseg][2];
  for (int i = 0; i < nseg; i++) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
  }
  int out = 0;
  for (int i = 1; i <= ulim; i++) {
    int count = 0;
    for (int j = 0; j < nseg; j++) {
      if (i >= arr[j][0] && i <= arr[j][1]) {
        count += 1;
      }
    }
    if (count == 0) {
      out += 1;
    }
  }
  printf("%d\n", out);
  for (int i = 1; i <= ulim; i++) {
    int count = 0;
    for (int j = 0; j < nseg; j++) {
      if (i >= arr[j][0] && i <= arr[j][1]) {
        count += 1;
      }
    }
    if (count == 0) {
      printf("%d ", i);
    }
  }
  return 0;
}
