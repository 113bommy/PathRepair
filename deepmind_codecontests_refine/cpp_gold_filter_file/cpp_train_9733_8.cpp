#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int min1, max1, min2, max2, min3, max3;
  scanf("%d %d %d %d %d %d", &min1, &max1, &min2, &max2, &min3, &max3);
  max1 = (max1 > n) ? n : max1;
  max2 = (max2 > n) ? n : max2;
  max3 = (max3 > n) ? n : max3;
  int i, j, k;
  int ans1, ans2, ans3;
  for (i = max1; i >= min1; i--) {
    for (j = (max2 > n - i) ? n - i - min3 + 1 : max2; j >= min2; j--) {
      for (k = n - i - j; k >= min3; k--) {
        if ((i + j + k) == n) {
          printf("%d %d %d\n", i, j, k);
          return 0;
        }
      }
    }
  }
  return 0;
}
