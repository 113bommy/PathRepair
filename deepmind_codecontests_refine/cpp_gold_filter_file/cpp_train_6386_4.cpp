#include <bits/stdc++.h>
int MINI3(int a, int b, int c) {
  int d;
  d = a < b ? a : b;
  d = d < c ? d : c;
  return d;
}
int main() {
  int arr[1005], ans[1005], maxa, maxb;
  int i, j, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  ans[n - 1] = arr[n - 1];
  ans[n - 2] = arr[n - 2] < ans[n - 1] ? arr[n - 2] : ans[n - 1];
  for (i = n - 3; i >= 0; i--) {
    maxa = ans[i + 1] > ans[i + 2] ? ans[i + 1] : ans[i + 2];
    ans[i] = maxa < arr[i] ? maxa : arr[i];
  }
  printf("%d\n", ans[0]);
  return 0;
}
