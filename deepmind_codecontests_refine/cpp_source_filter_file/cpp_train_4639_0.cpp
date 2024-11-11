#include <bits/stdc++.h>
int main() {
  int x, y, n, i;
  scanf("%d %d", &x, &y);
  scanf("%d", &n);
  int arr[n][3];
  double t = 200, d;
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    d = (x - arr[i][0]) * (x - arr[i][0]) + (y - arr[i][1]) * (y - arr[i][1]);
    d = sqrt(d);
    if (t > d / arr[i][2]) {
      t = d / arr[i][2];
    }
  }
  printf("%lf\n", t);
  return 0;
}
