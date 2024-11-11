#include <bits/stdc++.h>
int main() {
  int a, b = 1, max = 1, somonan, dem, n, k, i, mini;
  scanf("%d%d", &n, &k);
  int array[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }
  for (a = 0; a < n; a++) {
    for (i = 0; i < n - 1; i++) {
      if (array[i] > array[i + 1]) {
        dem = array[i];
        array[i] = array[i + 1];
        array[i + 1] = dem;
      }
    }
  }
  dem = 1;
  for (i = 0; i < n - 1; i++) {
    if (array[i] == array[i + 1]) {
      dem++;
      if (dem > max) {
        max = dem;
      }
    } else {
      b++;
      dem = 1;
    }
  }
  if (max < k) {
    somonan = 1;
  } else {
    if (max % k == 0) {
      somonan = max / k;
    } else {
      somonan = max / k + 1;
    }
  }
  mini = somonan * k * b - n;
  printf("%d", mini);
  return 0;
}
