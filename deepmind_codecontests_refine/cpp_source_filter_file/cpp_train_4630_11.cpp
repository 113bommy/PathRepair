#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  int count1 = 0;
  int count2 = 0;
  int count3 = 0;
  int min;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1) {
      count1++;
      continue;
    } else if (a[i] == 2) {
      count2++;
      continue;
    } else if (a[i] == 3) {
      count3++;
      continue;
    }
  }
  if (count1 < count2) {
    if (count1 < count3)
      min = count1;
    else if (count1 >= count3)
      min = count3;
  } else if (count1 >= count2) {
    if (count2 <= count3)
      min = count2;
    else
      min = count3;
  }
  printf("%d\n", min);
  int p = 0, q = 0, r = 0;
  while (min) {
    if (min == 0) break;
    for (int i = p + 1; i < n; i++) {
      if (a[i] == 1) {
        printf("%d ", i + 1);
        p = i;
        break;
      }
    }
    for (int j = q + 1; j < n; j++) {
      if (a[j] == 2) {
        printf("%d ", j + 1);
        q = j;
        break;
      }
    }
    for (int k = r + 1; k < n; k++) {
      if (a[k] == 3) {
        printf("%d\n", k + 1);
        r = k;
        break;
      }
    }
    min--;
  }
}
