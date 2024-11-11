#include <bits/stdc++.h>
void sort(int a[], int n) {
  int i;
  int j;
  for (i = 0; i <= 1000; i++) {
    for (j = 0; j <= 1000; j++) {
      if (a[j] > a[i]) {
        int buf = a[i];
        a[i] = a[j];
        a[j] = buf;
      }
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  int i, a[1001], x;
  for (i = 0; i <= 1000; i++) {
    a[i] = 0;
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    a[x] += 1;
  }
  int sum = 0;
  sort(a, 1001);
  for (i = 0; i < 1001; i++) {
    if (a[i] > 0) {
      sum += 1;
    }
  }
  printf("%d %d", a[999], sum);
  return 0;
}
