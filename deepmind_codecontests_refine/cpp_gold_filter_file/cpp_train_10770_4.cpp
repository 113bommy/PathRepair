#include <bits/stdc++.h>
int a[111111];
int n;
bool bin_search(int x) {
  int l, r, mid;
  l = 1;
  r = n;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (a[mid] < x)
      l = mid + 1;
    else if (a[mid] > x)
      r = mid - 1;
    else
      return 1;
  }
  return 0;
}
int main() {
  int l, x, y;
  int i;
  bool flag1, flag2;
  scanf("%d%d%d%d", &n, &l, &x, &y);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  flag1 = flag2 = 0;
  for (i = 1; i <= n; i++) {
    if (bin_search(a[i] + x)) {
      flag1 = 1;
      break;
    }
  }
  for (i = 1; i <= n; i++) {
    if (bin_search(a[i] + y)) {
      flag2 = 1;
      break;
    }
  }
  if (flag1 && flag2) {
    printf("0\n");
  } else {
    if (flag1) {
      printf("1\n%d\n", y);
    } else if (flag2) {
      printf("1\n%d\n", x);
    } else {
      for (i = 1; i <= n; i++) {
        if (bin_search(a[i] + x + y)) {
          flag1 = 1;
          break;
        }
      }
      if (flag1) {
        printf("1\n%d\n", a[i] + x);
      } else {
        for (i = 1; i <= n; i++) {
          if (bin_search(a[i] + y - x)) {
            if (a[i] - x >= 0) {
              printf("1\n%d\n", a[i] - x);
              flag1 = 1;
              break;
            } else if (a[i] + y <= l) {
              printf("1\n%d\n", a[i] + y);
              flag1 = 1;
              break;
            }
          }
        }
        if (!flag1) {
          printf("2\n%d %d\n", x, y);
        }
      }
    }
  }
  return 0;
}
