#include <bits/stdc++.h>
int main() {
  int n, i, j, a, index = 0, biggest = 0;
  scanf("%d", &n);
  int arr[1001] = {0};
  for (i = 0; i < n; i++) {
    scanf(" %d", &a);
    arr[a]++;
  }
  for (i = 0; i < 1001; i++) {
    if (arr[i] > biggest) {
      biggest = arr[i];
      index = i;
    }
  }
  if (n >= ((2 * arr[index]) - 1)) {
    printf("YES");
  } else {
    printf("NO");
  }
}
