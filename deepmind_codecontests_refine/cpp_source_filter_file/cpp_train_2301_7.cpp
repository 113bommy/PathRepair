#include <bits/stdc++.h>
int main() {
  int n, k, dem, max = 0, z = 0, i;
  scanf("%d%d", &n, &k);
  if (n == 0) printf("%d", k);
  int a[n], b[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[z] = a[i];
    z++;
  }
  for (i = 0; i < n; i++) {
    dem = 0;
    for (int j = i; j < n; j++) {
      if (a[j] == a[i]) dem++;
    }
    if (dem > max) max = dem;
  }
  int kq, c, sodoi, sopt = 1;
  for (i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] < a[j]) {
        sodoi = a[i];
        a[i] = a[j];
        a[j] = sodoi;
      }
    }
  }
  for (i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) sopt++;
  }
  c = max / k;
  if ((float)max / k > c) {
    c++;
    kq = sopt * c * k - n;
  }
  if (sopt == 1 && (float)max / k == c) kq = 0;
  printf("%d", kq);
  return 0;
}
