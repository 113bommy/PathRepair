#include <bits/stdc++.h>
int main() {
  int t, m;
  scanf("%d", &t);
  m = t - 1;
  int arr[t][2];
  while (t--) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    double a, b, c;
    a = (double)x;
    b = (double)y;
    c = (double)z;
    if (a > (double)c / b) {
      if (a > c) {
        arr[t][0] = -1;
        arr[t][1] = 1;
      } else if (a == c) {
        arr[t][0] = -1;
        arr[t][1] = 1;
      } else {
        arr[t][0] = 1;
        arr[t][1] = y;
      }
    } else {
      arr[t][0] = 1;
      arr[t][1] = -1;
    }
  }
  for (int i = m; i >= 0; i--) {
    printf("%d %d\n", arr[i][0], arr[i][1]);
  }
  return 0;
}
