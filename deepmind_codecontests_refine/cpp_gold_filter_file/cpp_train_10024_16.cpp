#include <bits/stdc++.h>
int main() {
  int arr[8899], x, i, j, k, min, max, in1, in2, out;
  scanf("%d", &x);
  for (i = 0; i < x; i++) {
    scanf("%d", &arr[i]);
  }
  max = arr[0];
  for (i = 1; i < x; i++) {
    if (arr[i] > max) {
      max = arr[i];
      in1 = i;
    }
  }
  min = arr[0];
  for (i = 1; i < x; i++) {
    if (arr[i] <= min) {
      min = arr[i];
      in2 = i;
    }
  }
  if (in2 < in1) {
    printf("%d\n", (in1 + ((x - 2) - in2)));
  } else if (in2 > in1) {
    printf("%d\n", (in1 + ((x - 1) - in2)));
  } else {
    printf("%d\n", 0);
  }
}
