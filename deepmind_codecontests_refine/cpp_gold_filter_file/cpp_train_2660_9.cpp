#include <bits/stdc++.h>
int main() {
  int a[4], temp, j, i;
  scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
  for (j = 1; j < 4; j++) {
    temp = a[j];
    i = j - 1;
    while (temp < a[i] && i >= 0) {
      a[i + 1] = a[i];
      i--;
    }
    a[i + 1] = temp;
  }
  if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3] || a[0] + a[2] > a[3])
    printf("TRIANGLE");
  else if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3] || a[0] + a[2] == a[3])
    printf("SEGMENT");
  else
    printf("IMPOSSIBLE");
  return 0;
}
