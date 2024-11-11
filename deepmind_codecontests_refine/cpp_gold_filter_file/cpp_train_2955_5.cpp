#include <bits/stdc++.h>
int main() {
  int n, a[100000], i, min, max;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  min = max = 1;
  for (i = 0; i < n; i++) {
    if ((a[i] > a[min - 1] && a[i] < a[max - 1]) ||
        (((a[i] >= a[max - 1] && min > max) ||
          (a[i] <= a[min - 1] && max > min)) &&
         max != min))
      break;
    if (a[i] > a[max - 1]) max = i + 1;
    if (a[i] < a[min - 1]) min = i + 1;
  }
  if (max != min && i < n)
    printf(
        "3\n%d %d %d\n",
        (min < (max < i + 1 ? max : i + 1) ? min : (max < i + 1 ? max : i + 1)),
        (((min < i + 1 ? min : i + 1) < max &&
          max < (min > i + 1 ? min : i + 1))
             ? max
             : (((max < i + 1 ? max : i + 1) < min &&
                 min < (max > i + 1 ? max : i + 1))
                    ? min
                    : i + 1)),
        (max > (max > i + 1 ? max : i + 1) ? max
                                           : (max > i + 1 ? max : i + 1)));
  else
    printf("0\n");
  return 0;
}
