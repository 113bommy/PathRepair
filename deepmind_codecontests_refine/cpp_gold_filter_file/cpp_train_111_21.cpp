#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int a[n], flag = 0, count, b[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    flag = flag + a[i];
  }
  int max = a[0];
  for (int i = 1; i < n; i++) {
    if (max < a[i]) max = a[i];
  }
  for (int i = max; i <= 10000; i++) {
    count = 0;
    for (int j = 0; j < n; j++) {
      b[j] = i - a[j];
      count = count + b[j];
    }
    if (count > flag) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
