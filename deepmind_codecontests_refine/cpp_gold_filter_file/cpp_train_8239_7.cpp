#include <bits/stdc++.h>
int main() {
  int N, i, value, len = 1, total = 0, j = 1;
  int *a, *index;
  scanf("%d", &N);
  a = (int *)malloc(sizeof(int) * N);
  index = (int *)malloc(sizeof(int) * N);
  for (i = 0; i < N; ++i) {
    scanf("%d", &a[i]);
    total += a[i];
  }
  value = a[0];
  index[0] = 1;
  for (i = 2; value <= total / 2 && i <= N; i++) {
    if (a[0] / 2 >= a[i - 1]) {
      value += a[i - 1];
      index[j] = i;
      len++;
      j++;
    }
  }
  if ((len == 1 && i != 2) || (value <= total / 2 && i == N + 1)) {
    printf("0");
    return 0;
  }
  printf("%d\n", len);
  for (i = 0; i < len; ++i) {
    printf("%d ", index[i]);
  }
}
