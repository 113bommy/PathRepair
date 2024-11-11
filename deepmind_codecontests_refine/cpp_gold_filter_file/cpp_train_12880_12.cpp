#include <bits/stdc++.h>
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int a[100001] = {0}, b[220000] = {0};
    int i, j, flag = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
      if (a[i] == 0)
        flag++;
      else {
        if (a[i] < 0) {
          b[a[i] + 200001]++;
        } else if (a[i] > 0) {
          b[a[i]]++;
        }
      }
    }
    int count = 0;
    for (i = 1; i < 220000; i++) {
      if (b[i] != 0) count++;
    }
    printf("%d\n", count);
  }
}
