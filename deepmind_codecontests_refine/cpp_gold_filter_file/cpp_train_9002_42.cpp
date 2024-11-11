#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x1, y1, x2, y2;
  long long int ans = 0;
  int arr[101][101];
  memset(arr, 0, sizeof(arr));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (int j = x1; j <= x2; j++) {
      for (int k = y1; k <= y2; k++) {
        arr[j][k]++;
      }
    }
  }
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      ans += arr[i][j];
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
