#include <bits/stdc++.h>
int main() {
  int a[110000], i, x, sum = 0, b[4] = {0};
  scanf("%d", &x);
  for (i = 0; i < x; i++) {
    scanf("%d", &a[i]);
    b[a[i] - 1]++;
  }
  if (b[0] <= b[2])
    sum += b[3] + b[2] + (b[1] + 1) / 2;
  else {
    sum += b[3] + b[2] + ((b[0] - b[2]) + 2 * b[1]) / 4;
    if (((b[0] - b[2]) + 2 * b[1]) % 4 != 0) sum++;
  }
  printf("%d\n", sum);
}
