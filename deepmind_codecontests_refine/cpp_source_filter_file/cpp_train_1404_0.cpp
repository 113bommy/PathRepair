#include <bits/stdc++.h>
void sort(int *a, int n) {
  int i, j, tmp;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }
}
int main() {
  int key, i, j, n, k, count, a[10000], b[10000], c[10000], d[10000];
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(a, n);
  c[0] = a[0];
  for (i = 1; i < n; i++) {
    c[i] = c[i - 1] + a[i];
  }
  for (i = 0; i < n; i++) {
    if (c[i] >= k) {
      key = c[i];
      count = i;
      break;
    }
  }
  if (key > k) {
    for (i = 0; i < count; i++) {
      for (j = 0; j < n; j++) {
        if (a[i] == b[j]) {
          d[i] = j + 1;
          b[j] = 0;
          break;
        }
      }
    }
    printf("%d\n", count);
    for (i = 0; i < count; i++) {
      printf("%d ", d[i]);
    }
    return 0;
  } else if (key == k) {
    count = count + 1;
    for (i = 0; i < count; i++) {
      for (j = 0; j < n; j++) {
        if (a[i] == b[j]) {
          d[i] = j + 1;
          b[j] = 0;
          break;
        }
      }
    }
    printf("%d\n", count);
    for (i = 0; i < count; i++) {
      printf("%d ", d[i]);
    }
    return 0;
  } else {
    printf("%d\n", n);
    for (i = 0; i < n; i++) {
      printf("%d", i + 1);
    }
  }
  return 0;
}
